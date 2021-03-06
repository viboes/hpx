//  Copyright (c)      2013 Thomas Heller
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <hpx/hpx.hpp>
#include <hpx/hpx_init.hpp>
#include <hpx/include/threads.hpp>
#include <hpx/include/local_lcos.hpp>
#include <hpx/util/lightweight_test.hpp>
#include <hpx/util/unwrapped.hpp>

using boost::program_options::variables_map;
using boost::program_options::options_description;
using boost::program_options::value;

using hpx::lcos::local::dataflow;
using hpx::util::bind;

using hpx::async;
using hpx::unique_future;
using hpx::shared_future;

using hpx::make_ready_future;

using hpx::init;
using hpx::finalize;

using hpx::util::report_errors;
using hpx::util::unwrapped;

///////////////////////////////////////////////////////////////////////////////

boost::atomic<boost::uint32_t> void_f_count;
boost::atomic<boost::uint32_t> int_f_count;

void void_f() {++void_f_count;}
int int_f() {++int_f_count; return 42; }

boost::atomic<boost::uint32_t> void_f1_count;
boost::atomic<boost::uint32_t> int_f1_count;

void void_f1(int) {++void_f1_count;}
int int_f1(int i) {++int_f1_count; return i+42; }

boost::atomic<boost::uint32_t> int_f2_count;
int int_f2(int l, int r) {++int_f2_count; return l + r; }

boost::atomic<boost::uint32_t> int_f_vector_count;

int int_f_vector(std::vector<int> const & vf)
{
    int sum = 0;
    BOOST_FOREACH(int f, vf)
    {
        sum += f;
    }
    return sum;
}

void function_pointers()
{
    void_f_count.store(0);
    int_f_count.store(0);
    void_f1_count.store(0);
    int_f1_count.store(0);
    int_f2_count.store(0);

    unique_future<void> f1 = dataflow(unwrapped(&void_f1), async(&int_f));
    unique_future<int>
        f2 = dataflow(
            unwrapped(&int_f1)
          , dataflow(
                unwrapped(&int_f1)
              , make_ready_future(42))
        );
    unique_future<int>
        f3 = dataflow(
            unwrapped(&int_f2)
          , dataflow(
                unwrapped(&int_f1)
              , make_ready_future(42)
            )
          , dataflow(
                unwrapped(&int_f1)
              , make_ready_future(37)
            )
        );

    int_f_vector_count.store(0);
    std::vector<unique_future<int> > vf;
    for(std::size_t i = 0; i < 10; ++i)
    {
        vf.push_back(dataflow(unwrapped(&int_f1), make_ready_future(42)));
    }
    unique_future<int> f4 = dataflow(unwrapped(&int_f_vector), boost::move(vf));

    unique_future<int>
        f5 = dataflow(
            unwrapped(&int_f1)
          , dataflow(
                unwrapped(&int_f1)
              , make_ready_future(42))
          , dataflow(
                unwrapped(&void_f)
              , make_ready_future())
        );

    hpx::wait(f1);
    HPX_TEST_EQ(f2.get(), 126);
    HPX_TEST_EQ(f3.get(), 163);
    HPX_TEST_EQ(f4.get(), 10 * 84);
    HPX_TEST_EQ(f5.get(), 126);
    HPX_TEST_EQ(void_f_count, 1u);
    HPX_TEST_EQ(int_f_count, 1u);
    HPX_TEST_EQ(void_f1_count, 1u);
    HPX_TEST_EQ(int_f1_count, 16u);
    HPX_TEST_EQ(int_f2_count, 1u);
}

///////////////////////////////////////////////////////////////////////////////

boost::atomic<boost::uint32_t> future_void_f1_count;
boost::atomic<boost::uint32_t> future_void_f2_count;

void future_void_f1(unique_future<void> f1) { HPX_TEST(f1.is_ready()); ++future_void_f1_count;}
void future_void_sf1(shared_future<void> f1) { HPX_TEST(f1.is_ready()); ++future_void_f1_count;}
void future_void_f2(unique_future<void> f1, unique_future<void> f2) { HPX_TEST(f1.is_ready()); HPX_TEST(f2.is_ready()); ++future_void_f2_count;}

boost::atomic<boost::uint32_t> future_int_f1_count;
boost::atomic<boost::uint32_t> future_int_f2_count;

int future_int_f1(unique_future<void> f1) { HPX_TEST(f1.is_ready()); ++future_int_f1_count; return 1;}
int future_int_f2(unique_future<int> f1, unique_future<int> f2)
{
    HPX_TEST(f1.is_ready()); HPX_TEST(f2.is_ready());
    ++future_int_f2_count;
    return f1.get() + f2.get();
}

boost::atomic<boost::uint32_t> future_int_f_vector_count;

int future_int_f_vector(std::vector<unique_future<int> >& vf)
{
    int sum = 0;
    BOOST_FOREACH(unique_future<int>& f, vf)
    {
        HPX_TEST(f.is_ready());
        sum += f.get();
    }
    return sum;
}

void future_function_pointers()
{
    future_void_f1_count.store(0);
    future_void_f2_count.store(0);

    unique_future<void> f1
        = dataflow(
            &future_void_f1, async(&future_void_sf1, shared_future<void>(make_ready_future()))
        );

    hpx::wait(f1);

    HPX_TEST_EQ(future_void_f1_count, 2u);
    future_void_f1_count.store(0);

    unique_future<void> f2 = dataflow(
        &future_void_f2
      , async(&future_void_sf1, shared_future<void>(make_ready_future()))
      , async(&future_void_sf1, shared_future<void>(make_ready_future()))
    );

    hpx::wait(f2);
    HPX_TEST_EQ(future_void_f1_count, 2u);
    HPX_TEST_EQ(future_void_f2_count, 1u);
    future_void_f1_count.store(0);
    future_void_f2_count.store(0);

    unique_future<int> f3 = dataflow(
        &future_int_f1
      , make_ready_future()
    );

    HPX_TEST_EQ(f3.get(), 1);
    HPX_TEST_EQ(future_int_f1_count, 1u);
    future_int_f1_count.store(0);

    unique_future<int> f4 = dataflow(
        &future_int_f2
      , dataflow(&future_int_f1, make_ready_future())
      , dataflow(&future_int_f1, make_ready_future())
    );

    HPX_TEST_EQ(f4.get(), 2);
    HPX_TEST_EQ(future_int_f1_count, 2u);
    HPX_TEST_EQ(future_int_f2_count, 1u);
    future_int_f1_count.store(0);
    future_int_f2_count.store(0);

    future_int_f_vector_count.store(0);
    std::vector<unique_future<int> > vf;
    for(std::size_t i = 0; i < 10; ++i)
    {
        vf.push_back(dataflow(&future_int_f1, make_ready_future()));
    }
    unique_future<int> f5 = dataflow(&future_int_f_vector, boost::ref(vf));

    HPX_TEST_EQ(f5.get(), 10);
}

///////////////////////////////////////////////////////////////////////////////
int hpx_main(variables_map&)
{
    function_pointers();
    future_function_pointers();

    return hpx::finalize();
}

///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
    // Configure application-specific options
    options_description
       desc_commandline("Usage: " HPX_APPLICATION_STRING " [options]");

    // We force this test to use several threads by default.
    using namespace boost::assign;
    std::vector<std::string> cfg;
    cfg += "hpx.os_threads=" +
        boost::lexical_cast<std::string>(hpx::threads::hardware_concurrency());

    // Initialize and run HPX
    HPX_TEST_EQ_MSG(init(desc_commandline, argc, argv, cfg), 0,
      "HPX main exited with non-zero status");
    return report_errors();
}

// Copyright (c) 2007-2013 Hartmut Kaiser
// Copyright (c) 2012-2013 Thomas Heller
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// This file has been automatically generated using the Boost.Wave tool.
// Do not edit manually.


    template <typename Arg0>
    void apply(BOOST_SCOPED_ENUM(launch) policy, naming::id_type const& gid,
        BOOST_FWD_REF(Arg0) arg0)
    {
        util::block_profiler_wrapper<profiler_tag> bp(apply_logger_);
        hpx::apply_c_cb<action_type>(this->get_gid(), gid,
            HPX_STD_BIND(&packaged_action::parcel_write_handler, this->impl_,
                HPX_STD_PLACEHOLDERS::_1),
            boost::forward<Arg0>( arg0 ));
    }
    template <typename Arg0>
    void apply(BOOST_SCOPED_ENUM(launch) policy, naming::address& addr,
        naming::id_type const& gid, BOOST_FWD_REF(Arg0) arg0)
    {
        util::block_profiler_wrapper<profiler_tag> bp(apply_logger_);
        hpx::apply_c_cb<action_type>(this->get_gid(), addr, gid,
            HPX_STD_BIND(&packaged_action::parcel_write_handler, this->impl_,
                HPX_STD_PLACEHOLDERS::_1),
            boost::forward<Arg0>( arg0 ));
    }
    template <typename Arg0>
    void apply_p(BOOST_SCOPED_ENUM(launch) policy, naming::id_type const& gid,
        threads::thread_priority priority, BOOST_FWD_REF(Arg0) arg0)
    {
        util::block_profiler_wrapper<profiler_tag> bp(apply_logger_);
        hpx::apply_c_p_cb<action_type>(this->get_gid(), gid, priority,
            HPX_STD_BIND(&packaged_action::parcel_write_handler, this->impl_,
                HPX_STD_PLACEHOLDERS::_1),
            boost::forward<Arg0>( arg0 ));
    }
    template <typename Arg0>
    void apply_p(BOOST_SCOPED_ENUM(launch) policy, naming::address& addr,
        naming::id_type const& gid, threads::thread_priority priority,
        BOOST_FWD_REF(Arg0) arg0)
    {
        util::block_profiler_wrapper<profiler_tag> bp(apply_logger_);
        hpx::apply_c_p_cb<action_type>(this->get_gid(), addr, gid, priority,
            HPX_STD_BIND(&packaged_action::parcel_write_handler, this->impl_,
                HPX_STD_PLACEHOLDERS::_1),
            boost::forward<Arg0>( arg0 ));
    }
    
    template <typename Arg0>
    packaged_action(naming::id_type const& gid,
            BOOST_FWD_REF(Arg0) arg0)
      : apply_logger_("packaged_action::apply")
    {
        LLCO_(info) << "packaged_action::packaged_action("
                    << hpx::actions::detail::get_action_name<action_type>()
                    << ", "
                    << gid
                    << ") args(" << (1 + 1) << ")";
        apply(launch::all, gid, boost::forward<Arg0>( arg0 ));
    }
    template <typename Arg0>
    packaged_action(naming::gid_type const& gid,
            threads::thread_priority priority,
            BOOST_FWD_REF(Arg0) arg0)
      : apply_logger_("packaged_action::apply")
    {
        LLCO_(info) << "packaged_action::packaged_action("
                    << hpx::actions::detail::get_action_name<action_type>()
                    << ", "
                    << gid
                    << ") args(" << (1 + 1) << ")";
        apply_p(launch::all, naming::id_type(gid, naming::id_type::unmanaged),
            priority, boost::forward<Arg0>( arg0 ));
    }
    template <typename Arg0 , typename Arg1>
    void apply(BOOST_SCOPED_ENUM(launch) policy, naming::id_type const& gid,
        BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1)
    {
        util::block_profiler_wrapper<profiler_tag> bp(apply_logger_);
        hpx::apply_c_cb<action_type>(this->get_gid(), gid,
            HPX_STD_BIND(&packaged_action::parcel_write_handler, this->impl_,
                HPX_STD_PLACEHOLDERS::_1),
            boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ));
    }
    template <typename Arg0 , typename Arg1>
    void apply(BOOST_SCOPED_ENUM(launch) policy, naming::address& addr,
        naming::id_type const& gid, BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1)
    {
        util::block_profiler_wrapper<profiler_tag> bp(apply_logger_);
        hpx::apply_c_cb<action_type>(this->get_gid(), addr, gid,
            HPX_STD_BIND(&packaged_action::parcel_write_handler, this->impl_,
                HPX_STD_PLACEHOLDERS::_1),
            boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ));
    }
    template <typename Arg0 , typename Arg1>
    void apply_p(BOOST_SCOPED_ENUM(launch) policy, naming::id_type const& gid,
        threads::thread_priority priority, BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1)
    {
        util::block_profiler_wrapper<profiler_tag> bp(apply_logger_);
        hpx::apply_c_p_cb<action_type>(this->get_gid(), gid, priority,
            HPX_STD_BIND(&packaged_action::parcel_write_handler, this->impl_,
                HPX_STD_PLACEHOLDERS::_1),
            boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ));
    }
    template <typename Arg0 , typename Arg1>
    void apply_p(BOOST_SCOPED_ENUM(launch) policy, naming::address& addr,
        naming::id_type const& gid, threads::thread_priority priority,
        BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1)
    {
        util::block_profiler_wrapper<profiler_tag> bp(apply_logger_);
        hpx::apply_c_p_cb<action_type>(this->get_gid(), addr, gid, priority,
            HPX_STD_BIND(&packaged_action::parcel_write_handler, this->impl_,
                HPX_STD_PLACEHOLDERS::_1),
            boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ));
    }
    
    template <typename Arg0 , typename Arg1>
    packaged_action(naming::id_type const& gid,
            BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1)
      : apply_logger_("packaged_action::apply")
    {
        LLCO_(info) << "packaged_action::packaged_action("
                    << hpx::actions::detail::get_action_name<action_type>()
                    << ", "
                    << gid
                    << ") args(" << (2 + 1) << ")";
        apply(launch::all, gid, boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ));
    }
    template <typename Arg0 , typename Arg1>
    packaged_action(naming::gid_type const& gid,
            threads::thread_priority priority,
            BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1)
      : apply_logger_("packaged_action::apply")
    {
        LLCO_(info) << "packaged_action::packaged_action("
                    << hpx::actions::detail::get_action_name<action_type>()
                    << ", "
                    << gid
                    << ") args(" << (2 + 1) << ")";
        apply_p(launch::all, naming::id_type(gid, naming::id_type::unmanaged),
            priority, boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ));
    }
    template <typename Arg0 , typename Arg1 , typename Arg2>
    void apply(BOOST_SCOPED_ENUM(launch) policy, naming::id_type const& gid,
        BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2)
    {
        util::block_profiler_wrapper<profiler_tag> bp(apply_logger_);
        hpx::apply_c_cb<action_type>(this->get_gid(), gid,
            HPX_STD_BIND(&packaged_action::parcel_write_handler, this->impl_,
                HPX_STD_PLACEHOLDERS::_1),
            boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ) , boost::forward<Arg2>( arg2 ));
    }
    template <typename Arg0 , typename Arg1 , typename Arg2>
    void apply(BOOST_SCOPED_ENUM(launch) policy, naming::address& addr,
        naming::id_type const& gid, BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2)
    {
        util::block_profiler_wrapper<profiler_tag> bp(apply_logger_);
        hpx::apply_c_cb<action_type>(this->get_gid(), addr, gid,
            HPX_STD_BIND(&packaged_action::parcel_write_handler, this->impl_,
                HPX_STD_PLACEHOLDERS::_1),
            boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ) , boost::forward<Arg2>( arg2 ));
    }
    template <typename Arg0 , typename Arg1 , typename Arg2>
    void apply_p(BOOST_SCOPED_ENUM(launch) policy, naming::id_type const& gid,
        threads::thread_priority priority, BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2)
    {
        util::block_profiler_wrapper<profiler_tag> bp(apply_logger_);
        hpx::apply_c_p_cb<action_type>(this->get_gid(), gid, priority,
            HPX_STD_BIND(&packaged_action::parcel_write_handler, this->impl_,
                HPX_STD_PLACEHOLDERS::_1),
            boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ) , boost::forward<Arg2>( arg2 ));
    }
    template <typename Arg0 , typename Arg1 , typename Arg2>
    void apply_p(BOOST_SCOPED_ENUM(launch) policy, naming::address& addr,
        naming::id_type const& gid, threads::thread_priority priority,
        BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2)
    {
        util::block_profiler_wrapper<profiler_tag> bp(apply_logger_);
        hpx::apply_c_p_cb<action_type>(this->get_gid(), addr, gid, priority,
            HPX_STD_BIND(&packaged_action::parcel_write_handler, this->impl_,
                HPX_STD_PLACEHOLDERS::_1),
            boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ) , boost::forward<Arg2>( arg2 ));
    }
    
    template <typename Arg0 , typename Arg1 , typename Arg2>
    packaged_action(naming::id_type const& gid,
            BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2)
      : apply_logger_("packaged_action::apply")
    {
        LLCO_(info) << "packaged_action::packaged_action("
                    << hpx::actions::detail::get_action_name<action_type>()
                    << ", "
                    << gid
                    << ") args(" << (3 + 1) << ")";
        apply(launch::all, gid, boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ) , boost::forward<Arg2>( arg2 ));
    }
    template <typename Arg0 , typename Arg1 , typename Arg2>
    packaged_action(naming::gid_type const& gid,
            threads::thread_priority priority,
            BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2)
      : apply_logger_("packaged_action::apply")
    {
        LLCO_(info) << "packaged_action::packaged_action("
                    << hpx::actions::detail::get_action_name<action_type>()
                    << ", "
                    << gid
                    << ") args(" << (3 + 1) << ")";
        apply_p(launch::all, naming::id_type(gid, naming::id_type::unmanaged),
            priority, boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ) , boost::forward<Arg2>( arg2 ));
    }
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3>
    void apply(BOOST_SCOPED_ENUM(launch) policy, naming::id_type const& gid,
        BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3)
    {
        util::block_profiler_wrapper<profiler_tag> bp(apply_logger_);
        hpx::apply_c_cb<action_type>(this->get_gid(), gid,
            HPX_STD_BIND(&packaged_action::parcel_write_handler, this->impl_,
                HPX_STD_PLACEHOLDERS::_1),
            boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ) , boost::forward<Arg2>( arg2 ) , boost::forward<Arg3>( arg3 ));
    }
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3>
    void apply(BOOST_SCOPED_ENUM(launch) policy, naming::address& addr,
        naming::id_type const& gid, BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3)
    {
        util::block_profiler_wrapper<profiler_tag> bp(apply_logger_);
        hpx::apply_c_cb<action_type>(this->get_gid(), addr, gid,
            HPX_STD_BIND(&packaged_action::parcel_write_handler, this->impl_,
                HPX_STD_PLACEHOLDERS::_1),
            boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ) , boost::forward<Arg2>( arg2 ) , boost::forward<Arg3>( arg3 ));
    }
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3>
    void apply_p(BOOST_SCOPED_ENUM(launch) policy, naming::id_type const& gid,
        threads::thread_priority priority, BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3)
    {
        util::block_profiler_wrapper<profiler_tag> bp(apply_logger_);
        hpx::apply_c_p_cb<action_type>(this->get_gid(), gid, priority,
            HPX_STD_BIND(&packaged_action::parcel_write_handler, this->impl_,
                HPX_STD_PLACEHOLDERS::_1),
            boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ) , boost::forward<Arg2>( arg2 ) , boost::forward<Arg3>( arg3 ));
    }
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3>
    void apply_p(BOOST_SCOPED_ENUM(launch) policy, naming::address& addr,
        naming::id_type const& gid, threads::thread_priority priority,
        BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3)
    {
        util::block_profiler_wrapper<profiler_tag> bp(apply_logger_);
        hpx::apply_c_p_cb<action_type>(this->get_gid(), addr, gid, priority,
            HPX_STD_BIND(&packaged_action::parcel_write_handler, this->impl_,
                HPX_STD_PLACEHOLDERS::_1),
            boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ) , boost::forward<Arg2>( arg2 ) , boost::forward<Arg3>( arg3 ));
    }
    
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3>
    packaged_action(naming::id_type const& gid,
            BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3)
      : apply_logger_("packaged_action::apply")
    {
        LLCO_(info) << "packaged_action::packaged_action("
                    << hpx::actions::detail::get_action_name<action_type>()
                    << ", "
                    << gid
                    << ") args(" << (4 + 1) << ")";
        apply(launch::all, gid, boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ) , boost::forward<Arg2>( arg2 ) , boost::forward<Arg3>( arg3 ));
    }
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3>
    packaged_action(naming::gid_type const& gid,
            threads::thread_priority priority,
            BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3)
      : apply_logger_("packaged_action::apply")
    {
        LLCO_(info) << "packaged_action::packaged_action("
                    << hpx::actions::detail::get_action_name<action_type>()
                    << ", "
                    << gid
                    << ") args(" << (4 + 1) << ")";
        apply_p(launch::all, naming::id_type(gid, naming::id_type::unmanaged),
            priority, boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ) , boost::forward<Arg2>( arg2 ) , boost::forward<Arg3>( arg3 ));
    }
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4>
    void apply(BOOST_SCOPED_ENUM(launch) policy, naming::id_type const& gid,
        BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4)
    {
        util::block_profiler_wrapper<profiler_tag> bp(apply_logger_);
        hpx::apply_c_cb<action_type>(this->get_gid(), gid,
            HPX_STD_BIND(&packaged_action::parcel_write_handler, this->impl_,
                HPX_STD_PLACEHOLDERS::_1),
            boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ) , boost::forward<Arg2>( arg2 ) , boost::forward<Arg3>( arg3 ) , boost::forward<Arg4>( arg4 ));
    }
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4>
    void apply(BOOST_SCOPED_ENUM(launch) policy, naming::address& addr,
        naming::id_type const& gid, BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4)
    {
        util::block_profiler_wrapper<profiler_tag> bp(apply_logger_);
        hpx::apply_c_cb<action_type>(this->get_gid(), addr, gid,
            HPX_STD_BIND(&packaged_action::parcel_write_handler, this->impl_,
                HPX_STD_PLACEHOLDERS::_1),
            boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ) , boost::forward<Arg2>( arg2 ) , boost::forward<Arg3>( arg3 ) , boost::forward<Arg4>( arg4 ));
    }
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4>
    void apply_p(BOOST_SCOPED_ENUM(launch) policy, naming::id_type const& gid,
        threads::thread_priority priority, BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4)
    {
        util::block_profiler_wrapper<profiler_tag> bp(apply_logger_);
        hpx::apply_c_p_cb<action_type>(this->get_gid(), gid, priority,
            HPX_STD_BIND(&packaged_action::parcel_write_handler, this->impl_,
                HPX_STD_PLACEHOLDERS::_1),
            boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ) , boost::forward<Arg2>( arg2 ) , boost::forward<Arg3>( arg3 ) , boost::forward<Arg4>( arg4 ));
    }
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4>
    void apply_p(BOOST_SCOPED_ENUM(launch) policy, naming::address& addr,
        naming::id_type const& gid, threads::thread_priority priority,
        BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4)
    {
        util::block_profiler_wrapper<profiler_tag> bp(apply_logger_);
        hpx::apply_c_p_cb<action_type>(this->get_gid(), addr, gid, priority,
            HPX_STD_BIND(&packaged_action::parcel_write_handler, this->impl_,
                HPX_STD_PLACEHOLDERS::_1),
            boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ) , boost::forward<Arg2>( arg2 ) , boost::forward<Arg3>( arg3 ) , boost::forward<Arg4>( arg4 ));
    }
    
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4>
    packaged_action(naming::id_type const& gid,
            BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4)
      : apply_logger_("packaged_action::apply")
    {
        LLCO_(info) << "packaged_action::packaged_action("
                    << hpx::actions::detail::get_action_name<action_type>()
                    << ", "
                    << gid
                    << ") args(" << (5 + 1) << ")";
        apply(launch::all, gid, boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ) , boost::forward<Arg2>( arg2 ) , boost::forward<Arg3>( arg3 ) , boost::forward<Arg4>( arg4 ));
    }
    template <typename Arg0 , typename Arg1 , typename Arg2 , typename Arg3 , typename Arg4>
    packaged_action(naming::gid_type const& gid,
            threads::thread_priority priority,
            BOOST_FWD_REF(Arg0) arg0 , BOOST_FWD_REF(Arg1) arg1 , BOOST_FWD_REF(Arg2) arg2 , BOOST_FWD_REF(Arg3) arg3 , BOOST_FWD_REF(Arg4) arg4)
      : apply_logger_("packaged_action::apply")
    {
        LLCO_(info) << "packaged_action::packaged_action("
                    << hpx::actions::detail::get_action_name<action_type>()
                    << ", "
                    << gid
                    << ") args(" << (5 + 1) << ")";
        apply_p(launch::all, naming::id_type(gid, naming::id_type::unmanaged),
            priority, boost::forward<Arg0>( arg0 ) , boost::forward<Arg1>( arg1 ) , boost::forward<Arg2>( arg2 ) , boost::forward<Arg3>( arg3 ) , boost::forward<Arg4>( arg4 ));
    }

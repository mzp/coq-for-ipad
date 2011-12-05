#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN64
typedef __int64 value;
#else
typedef long value;
#endif
extern value caml_alloc_dummy();
extern value caml_alloc_dummy_float();
extern value caml_update_dummy();
extern value caml_array_get_addr();
extern value caml_array_get_float();
extern value caml_array_get();
extern value caml_array_set_addr();
extern value caml_array_set_float();
extern value caml_array_set();
extern value caml_array_unsafe_get_float();
extern value caml_array_unsafe_get();
extern value caml_array_unsafe_set_addr();
extern value caml_array_unsafe_set_float();
extern value caml_array_unsafe_set();
extern value caml_make_vect();
extern value caml_make_array();
extern value caml_compare();
extern value caml_equal();
extern value caml_notequal();
extern value caml_lessthan();
extern value caml_lessequal();
extern value caml_greaterthan();
extern value caml_greaterequal();
extern value caml_output_value();
extern value caml_output_value_to_string();
extern value caml_output_value_to_buffer();
extern value caml_format_float();
extern value caml_float_of_string();
extern value caml_int_of_float();
extern value caml_float_of_int();
extern value caml_neg_float();
extern value caml_abs_float();
extern value caml_add_float();
extern value caml_sub_float();
extern value caml_mul_float();
extern value caml_div_float();
extern value caml_exp_float();
extern value caml_floor_float();
extern value caml_fmod_float();
extern value caml_frexp_float();
extern value caml_ldexp_float();
extern value caml_log_float();
extern value caml_log10_float();
extern value caml_modf_float();
extern value caml_sqrt_float();
extern value caml_power_float();
extern value caml_sin_float();
extern value caml_sinh_float();
extern value caml_cos_float();
extern value caml_cosh_float();
extern value caml_tan_float();
extern value caml_tanh_float();
extern value caml_asin_float();
extern value caml_acos_float();
extern value caml_atan_float();
extern value caml_atan2_float();
extern value caml_ceil_float();
extern value caml_expm1_float();
extern value caml_log1p_float();
extern value caml_eq_float();
extern value caml_neq_float();
extern value caml_le_float();
extern value caml_lt_float();
extern value caml_ge_float();
extern value caml_gt_float();
extern value caml_float_compare();
extern value caml_classify_float();
extern value caml_gc_stat();
extern value caml_gc_quick_stat();
extern value caml_gc_counters();
extern value caml_gc_get();
extern value caml_gc_set();
extern value caml_gc_minor();
extern value caml_gc_major();
extern value caml_gc_full_major();
extern value caml_gc_major_slice();
extern value caml_gc_compaction();
extern value caml_hash_univ_param();
extern value caml_input_value();
extern value caml_input_value_from_string();
extern value caml_marshal_data_size();
extern value caml_int_compare();
extern value caml_int_of_string();
extern value caml_format_int();
extern value caml_int32_neg();
extern value caml_int32_add();
extern value caml_int32_sub();
extern value caml_int32_mul();
extern value caml_int32_div();
extern value caml_int32_mod();
extern value caml_int32_and();
extern value caml_int32_or();
extern value caml_int32_xor();
extern value caml_int32_shift_left();
extern value caml_int32_shift_right();
extern value caml_int32_shift_right_unsigned();
extern value caml_int32_of_int();
extern value caml_int32_to_int();
extern value caml_int32_of_float();
extern value caml_int32_to_float();
extern value caml_int32_compare();
extern value caml_int32_format();
extern value caml_int32_of_string();
extern value caml_int32_bits_of_float();
extern value caml_int32_float_of_bits();
extern value caml_int64_neg();
extern value caml_int64_add();
extern value caml_int64_sub();
extern value caml_int64_mul();
extern value caml_int64_div();
extern value caml_int64_mod();
extern value caml_int64_and();
extern value caml_int64_or();
extern value caml_int64_xor();
extern value caml_int64_shift_left();
extern value caml_int64_shift_right();
extern value caml_int64_shift_right_unsigned();
extern value caml_int64_of_int();
extern value caml_int64_to_int();
extern value caml_int64_of_float();
extern value caml_int64_to_float();
extern value caml_int64_of_int32();
extern value caml_int64_to_int32();
extern value caml_int64_of_nativeint();
extern value caml_int64_to_nativeint();
extern value caml_int64_compare();
extern value caml_int64_format();
extern value caml_int64_of_string();
extern value caml_int64_bits_of_float();
extern value caml_int64_float_of_bits();
extern value caml_nativeint_neg();
extern value caml_nativeint_add();
extern value caml_nativeint_sub();
extern value caml_nativeint_mul();
extern value caml_nativeint_div();
extern value caml_nativeint_mod();
extern value caml_nativeint_and();
extern value caml_nativeint_or();
extern value caml_nativeint_xor();
extern value caml_nativeint_shift_left();
extern value caml_nativeint_shift_right();
extern value caml_nativeint_shift_right_unsigned();
extern value caml_nativeint_of_int();
extern value caml_nativeint_to_int();
extern value caml_nativeint_of_float();
extern value caml_nativeint_to_float();
extern value caml_nativeint_of_int32();
extern value caml_nativeint_to_int32();
extern value caml_nativeint_compare();
extern value caml_nativeint_format();
extern value caml_nativeint_of_string();
extern value caml_ml_open_descriptor_in();
extern value caml_ml_open_descriptor_out();
extern value caml_ml_out_channels_list();
extern value caml_channel_descriptor();
extern value caml_ml_close_channel();
extern value caml_ml_channel_size();
extern value caml_ml_channel_size_64();
extern value caml_ml_set_binary_mode();
extern value caml_ml_flush_partial();
extern value caml_ml_flush();
extern value caml_ml_output_char();
extern value caml_ml_output_int();
extern value caml_ml_output_partial();
extern value caml_ml_output();
extern value caml_ml_seek_out();
extern value caml_ml_seek_out_64();
extern value caml_ml_pos_out();
extern value caml_ml_pos_out_64();
extern value caml_ml_input_char();
extern value caml_ml_input_int();
extern value caml_ml_input();
extern value caml_ml_seek_in();
extern value caml_ml_seek_in_64();
extern value caml_ml_pos_in();
extern value caml_ml_pos_in_64();
extern value caml_ml_input_scan_line();
extern value caml_lex_engine();
extern value caml_new_lex_engine();
extern value caml_md5_string();
extern value caml_md5_chan();
extern value caml_get_global_data();
extern value caml_get_section_table();
extern value caml_reify_bytecode();
extern value caml_realloc_global();
extern value caml_get_current_environment();
extern value caml_invoke_traced_function();
extern value caml_static_alloc();
extern value caml_static_free();
extern value caml_static_release_bytecode();
extern value caml_static_resize();
extern value caml_obj_is_block();
extern value caml_obj_tag();
extern value caml_obj_set_tag();
extern value caml_obj_block();
extern value caml_obj_dup();
extern value caml_obj_truncate();
extern value caml_obj_add_offset();
extern value caml_lazy_follow_forward();
extern value caml_lazy_make_forward();
extern value caml_get_public_method();
extern value caml_parse_engine();
extern value caml_set_parser_trace();
extern value caml_install_signal_handler();
extern value caml_ml_string_length();
extern value caml_create_string();
extern value caml_string_get();
extern value caml_string_set();
extern value caml_string_equal();
extern value caml_string_notequal();
extern value caml_string_compare();
extern value caml_string_lessthan();
extern value caml_string_lessequal();
extern value caml_string_greaterthan();
extern value caml_string_greaterequal();
extern value caml_blit_string();
extern value caml_fill_string();
extern value caml_is_printable();
extern value caml_bitvect_test();
extern value caml_sys_exit();
extern value caml_sys_open();
extern value caml_sys_close();
extern value caml_sys_file_exists();
extern value caml_sys_is_directory();
extern value caml_sys_remove();
extern value caml_sys_rename();
extern value caml_sys_chdir();
extern value caml_sys_getcwd();
extern value caml_sys_getenv();
extern value caml_sys_get_argv();
extern value caml_sys_system_command();
extern value caml_sys_time();
extern value caml_sys_random_seed();
extern value caml_sys_get_config();
extern value caml_sys_read_directory();
extern value caml_terminfo_setup();
extern value caml_terminfo_backup();
extern value caml_terminfo_standout();
extern value caml_terminfo_resume();
extern value caml_register_named_value();
extern value caml_weak_create();
extern value caml_weak_set();
extern value caml_weak_get();
extern value caml_weak_get_copy();
extern value caml_weak_check();
extern value caml_weak_blit();
extern value caml_final_register();
extern value caml_final_release();
extern value caml_ensure_stack_capacity();
extern value caml_dynlink_open_lib();
extern value caml_dynlink_close_lib();
extern value caml_dynlink_lookup_symbol();
extern value caml_dynlink_add_primitive();
extern value caml_dynlink_get_current_libs();
extern value caml_record_backtrace();
extern value caml_backtrace_status();
extern value caml_get_exception_backtrace();
extern value re_replacement_text();
extern value re_search_backward();
extern value re_search_forward();
extern value re_partial_match();
extern value re_string_match();
extern value unix_dup();
extern value unix_close();
extern value unix_waitpid();
extern value unix_accept();
extern value unix_error_message();
extern value unix_environment();
extern value unix_putenv();
extern value unix_execv();
extern value unix_execve();
extern value unix_execvp();
extern value unix_execvpe();
extern value unix_fork();
extern value unix_wait();
extern value unix_getpid();
extern value unix_getppid();
extern value unix_nice();
extern value unix_open();
extern value unix_lseek();
extern value unix_truncate();
extern value unix_ftruncate();
extern value unix_stat();
extern value unix_lstat();
extern value unix_fstat();
extern value unix_isatty();
extern value unix_lseek_64();
extern value unix_truncate_64();
extern value unix_ftruncate_64();
extern value unix_stat_64();
extern value unix_lstat_64();
extern value unix_fstat_64();
extern value unix_unlink();
extern value unix_rename();
extern value unix_link();
extern value unix_chmod();
extern value unix_fchmod();
extern value unix_chown();
extern value unix_fchown();
extern value unix_umask();
extern value unix_access();
extern value unix_dup2();
extern value unix_set_nonblock();
extern value unix_clear_nonblock();
extern value unix_set_close_on_exec();
extern value unix_clear_close_on_exec();
extern value unix_mkdir();
extern value unix_rmdir();
extern value unix_chdir();
extern value unix_getcwd();
extern value unix_chroot();
extern value unix_opendir();
extern value unix_readdir();
extern value unix_rewinddir();
extern value unix_closedir();
extern value unix_pipe();
extern value unix_mkfifo();
extern value unix_symlink();
extern value unix_readlink();
extern value unix_select();
extern value unix_lockf();
extern value unix_kill();
extern value unix_sigprocmask();
extern value unix_sigpending();
extern value unix_sigsuspend();
extern value unix_time();
extern value unix_gettimeofday();
extern value unix_gmtime();
extern value unix_localtime();
extern value unix_mktime();
extern value unix_alarm();
extern value unix_sleep();
extern value unix_times();
extern value unix_utimes();
extern value unix_getitimer();
extern value unix_setitimer();
extern value unix_getuid();
extern value unix_geteuid();
extern value unix_setuid();
extern value unix_getgid();
extern value unix_getegid();
extern value unix_setgid();
extern value unix_getgroups();
extern value unix_setgroups();
extern value unix_initgroups();
extern value unix_getlogin();
extern value unix_getpwnam();
extern value unix_getgrnam();
extern value unix_getpwuid();
extern value unix_getgrgid();
extern value unix_inet_addr_of_string();
extern value unix_string_of_inet_addr();
extern value unix_socket();
extern value unix_socketpair();
extern value unix_bind();
extern value unix_connect();
extern value unix_listen();
extern value unix_shutdown();
extern value unix_getsockname();
extern value unix_getpeername();
extern value unix_gethostname();
extern value unix_gethostbyname();
extern value unix_gethostbyaddr();
extern value unix_getprotobyname();
extern value unix_getprotobynumber();
extern value unix_getservbyname();
extern value unix_getservbyport();
extern value unix_tcgetattr();
extern value unix_tcsetattr();
extern value unix_tcsendbreak();
extern value unix_tcdrain();
extern value unix_tcflush();
extern value unix_tcflow();
extern value unix_setsid();
extern value unix_getnameinfo();
extern value unix_getaddrinfo();
extern value unix_getsockopt();
extern value unix_setsockopt();
extern value unix_sendto();
extern value unix_send();
extern value unix_recvfrom();
extern value unix_recv();
extern value unix_single_write();
extern value unix_write();
extern value unix_read();
extern value set_digit_nat();
extern value mult_digit_nat();
extern value blit_nat();
extern value num_digits_nat();
extern value create_nat();
extern value div_digit_nat();
extern value square_nat();
extern value set_to_zero_nat();
extern value is_digit_zero();
extern value is_digit_int();
extern value nth_digit_nat();
extern value div_nat();
extern value add_nat();
extern value shift_right_nat();
extern value num_leading_zero_bits_in_digit();
extern value complement_nat();
extern value compare_nat();
extern value initialize_nat();
extern value lxor_digit_nat();
extern value lor_digit_nat();
extern value land_digit_nat();
extern value compare_digits_nat();
extern value shift_left_nat();
extern value mult_nat();
extern value sub_nat();
extern value decr_nat();
extern value incr_nat();
extern value is_digit_odd();
extern value is_digit_normalized();
extern value nth_digit_nat_native();
extern value set_digit_nat_native();
extern value coq_push_ra();
extern value coq_push_arguments();
extern value coq_push_val();
extern value coq_interprete_ml();
extern value coq_set_drawinstr();
extern value get_coq_transp_value();
extern value coq_set_transp_value();
extern value coq_push_vstack();
extern value coq_offset_tcode();
extern value coq_offset_closure();
extern value coq_makeaccu();
extern value realloc_coq_atom_tbl();
extern value get_coq_atom_tbl();
extern value coq_int_tcode();
extern value coq_offset();
extern value coq_closure_arity();
extern value coq_accucond();
extern value coq_is_accumulate_code();
extern value coq_kind_of_closure();
extern value coq_pushpop();
extern value init_coq_vm();
extern value accumulate_code();
extern value coq_tcode_of_code();
extern value coq_eval_tcode();
extern value get_coq_global_boxed();
extern value realloc_coq_global_boxed();
extern value get_coq_global_data();
extern value realloc_coq_global_data();
extern value coq_static_free();
typedef value (*primitive)();
primitive caml_builtin_cprim[] = {
  caml_alloc_dummy,
  caml_alloc_dummy_float,
  caml_update_dummy,
  caml_array_get_addr,
  caml_array_get_float,
  caml_array_get,
  caml_array_set_addr,
  caml_array_set_float,
  caml_array_set,
  caml_array_unsafe_get_float,
  caml_array_unsafe_get,
  caml_array_unsafe_set_addr,
  caml_array_unsafe_set_float,
  caml_array_unsafe_set,
  caml_make_vect,
  caml_make_array,
  caml_compare,
  caml_equal,
  caml_notequal,
  caml_lessthan,
  caml_lessequal,
  caml_greaterthan,
  caml_greaterequal,
  caml_output_value,
  caml_output_value_to_string,
  caml_output_value_to_buffer,
  caml_format_float,
  caml_float_of_string,
  caml_int_of_float,
  caml_float_of_int,
  caml_neg_float,
  caml_abs_float,
  caml_add_float,
  caml_sub_float,
  caml_mul_float,
  caml_div_float,
  caml_exp_float,
  caml_floor_float,
  caml_fmod_float,
  caml_frexp_float,
  caml_ldexp_float,
  caml_log_float,
  caml_log10_float,
  caml_modf_float,
  caml_sqrt_float,
  caml_power_float,
  caml_sin_float,
  caml_sinh_float,
  caml_cos_float,
  caml_cosh_float,
  caml_tan_float,
  caml_tanh_float,
  caml_asin_float,
  caml_acos_float,
  caml_atan_float,
  caml_atan2_float,
  caml_ceil_float,
  caml_expm1_float,
  caml_log1p_float,
  caml_eq_float,
  caml_neq_float,
  caml_le_float,
  caml_lt_float,
  caml_ge_float,
  caml_gt_float,
  caml_float_compare,
  caml_classify_float,
  caml_gc_stat,
  caml_gc_quick_stat,
  caml_gc_counters,
  caml_gc_get,
  caml_gc_set,
  caml_gc_minor,
  caml_gc_major,
  caml_gc_full_major,
  caml_gc_major_slice,
  caml_gc_compaction,
  caml_hash_univ_param,
  caml_input_value,
  caml_input_value_from_string,
  caml_marshal_data_size,
  caml_int_compare,
  caml_int_of_string,
  caml_format_int,
  caml_int32_neg,
  caml_int32_add,
  caml_int32_sub,
  caml_int32_mul,
  caml_int32_div,
  caml_int32_mod,
  caml_int32_and,
  caml_int32_or,
  caml_int32_xor,
  caml_int32_shift_left,
  caml_int32_shift_right,
  caml_int32_shift_right_unsigned,
  caml_int32_of_int,
  caml_int32_to_int,
  caml_int32_of_float,
  caml_int32_to_float,
  caml_int32_compare,
  caml_int32_format,
  caml_int32_of_string,
  caml_int32_bits_of_float,
  caml_int32_float_of_bits,
  caml_int64_neg,
  caml_int64_add,
  caml_int64_sub,
  caml_int64_mul,
  caml_int64_div,
  caml_int64_mod,
  caml_int64_and,
  caml_int64_or,
  caml_int64_xor,
  caml_int64_shift_left,
  caml_int64_shift_right,
  caml_int64_shift_right_unsigned,
  caml_int64_of_int,
  caml_int64_to_int,
  caml_int64_of_float,
  caml_int64_to_float,
  caml_int64_of_int32,
  caml_int64_to_int32,
  caml_int64_of_nativeint,
  caml_int64_to_nativeint,
  caml_int64_compare,
  caml_int64_format,
  caml_int64_of_string,
  caml_int64_bits_of_float,
  caml_int64_float_of_bits,
  caml_nativeint_neg,
  caml_nativeint_add,
  caml_nativeint_sub,
  caml_nativeint_mul,
  caml_nativeint_div,
  caml_nativeint_mod,
  caml_nativeint_and,
  caml_nativeint_or,
  caml_nativeint_xor,
  caml_nativeint_shift_left,
  caml_nativeint_shift_right,
  caml_nativeint_shift_right_unsigned,
  caml_nativeint_of_int,
  caml_nativeint_to_int,
  caml_nativeint_of_float,
  caml_nativeint_to_float,
  caml_nativeint_of_int32,
  caml_nativeint_to_int32,
  caml_nativeint_compare,
  caml_nativeint_format,
  caml_nativeint_of_string,
  caml_ml_open_descriptor_in,
  caml_ml_open_descriptor_out,
  caml_ml_out_channels_list,
  caml_channel_descriptor,
  caml_ml_close_channel,
  caml_ml_channel_size,
  caml_ml_channel_size_64,
  caml_ml_set_binary_mode,
  caml_ml_flush_partial,
  caml_ml_flush,
  caml_ml_output_char,
  caml_ml_output_int,
  caml_ml_output_partial,
  caml_ml_output,
  caml_ml_seek_out,
  caml_ml_seek_out_64,
  caml_ml_pos_out,
  caml_ml_pos_out_64,
  caml_ml_input_char,
  caml_ml_input_int,
  caml_ml_input,
  caml_ml_seek_in,
  caml_ml_seek_in_64,
  caml_ml_pos_in,
  caml_ml_pos_in_64,
  caml_ml_input_scan_line,
  caml_lex_engine,
  caml_new_lex_engine,
  caml_md5_string,
  caml_md5_chan,
  caml_get_global_data,
  caml_get_section_table,
  caml_reify_bytecode,
  caml_realloc_global,
  caml_get_current_environment,
  caml_invoke_traced_function,
  caml_static_alloc,
  caml_static_free,
  caml_static_release_bytecode,
  caml_static_resize,
  caml_obj_is_block,
  caml_obj_tag,
  caml_obj_set_tag,
  caml_obj_block,
  caml_obj_dup,
  caml_obj_truncate,
  caml_obj_add_offset,
  caml_lazy_follow_forward,
  caml_lazy_make_forward,
  caml_get_public_method,
  caml_parse_engine,
  caml_set_parser_trace,
  caml_install_signal_handler,
  caml_ml_string_length,
  caml_create_string,
  caml_string_get,
  caml_string_set,
  caml_string_equal,
  caml_string_notequal,
  caml_string_compare,
  caml_string_lessthan,
  caml_string_lessequal,
  caml_string_greaterthan,
  caml_string_greaterequal,
  caml_blit_string,
  caml_fill_string,
  caml_is_printable,
  caml_bitvect_test,
  caml_sys_exit,
  caml_sys_open,
  caml_sys_close,
  caml_sys_file_exists,
  caml_sys_is_directory,
  caml_sys_remove,
  caml_sys_rename,
  caml_sys_chdir,
  caml_sys_getcwd,
  caml_sys_getenv,
  caml_sys_get_argv,
  caml_sys_system_command,
  caml_sys_time,
  caml_sys_random_seed,
  caml_sys_get_config,
  caml_sys_read_directory,
  caml_terminfo_setup,
  caml_terminfo_backup,
  caml_terminfo_standout,
  caml_terminfo_resume,
  caml_register_named_value,
  caml_weak_create,
  caml_weak_set,
  caml_weak_get,
  caml_weak_get_copy,
  caml_weak_check,
  caml_weak_blit,
  caml_final_register,
  caml_final_release,
  caml_ensure_stack_capacity,
  caml_dynlink_open_lib,
  caml_dynlink_close_lib,
  caml_dynlink_lookup_symbol,
  caml_dynlink_add_primitive,
  caml_dynlink_get_current_libs,
  caml_record_backtrace,
  caml_backtrace_status,
  caml_get_exception_backtrace,
  re_replacement_text,
  re_search_backward,
  re_search_forward,
  re_partial_match,
  re_string_match,
  unix_dup,
  unix_close,
  unix_waitpid,
  unix_accept,
  unix_error_message,
  unix_environment,
  unix_putenv,
  unix_execv,
  unix_execve,
  unix_execvp,
  unix_execvpe,
  unix_fork,
  unix_wait,
  unix_getpid,
  unix_getppid,
  unix_nice,
  unix_open,
  unix_lseek,
  unix_truncate,
  unix_ftruncate,
  unix_stat,
  unix_lstat,
  unix_fstat,
  unix_isatty,
  unix_lseek_64,
  unix_truncate_64,
  unix_ftruncate_64,
  unix_stat_64,
  unix_lstat_64,
  unix_fstat_64,
  unix_unlink,
  unix_rename,
  unix_link,
  unix_chmod,
  unix_fchmod,
  unix_chown,
  unix_fchown,
  unix_umask,
  unix_access,
  unix_dup2,
  unix_set_nonblock,
  unix_clear_nonblock,
  unix_set_close_on_exec,
  unix_clear_close_on_exec,
  unix_mkdir,
  unix_rmdir,
  unix_chdir,
  unix_getcwd,
  unix_chroot,
  unix_opendir,
  unix_readdir,
  unix_rewinddir,
  unix_closedir,
  unix_pipe,
  unix_mkfifo,
  unix_symlink,
  unix_readlink,
  unix_select,
  unix_lockf,
  unix_kill,
  unix_sigprocmask,
  unix_sigpending,
  unix_sigsuspend,
  unix_time,
  unix_gettimeofday,
  unix_gmtime,
  unix_localtime,
  unix_mktime,
  unix_alarm,
  unix_sleep,
  unix_times,
  unix_utimes,
  unix_getitimer,
  unix_setitimer,
  unix_getuid,
  unix_geteuid,
  unix_setuid,
  unix_getgid,
  unix_getegid,
  unix_setgid,
  unix_getgroups,
  unix_setgroups,
  unix_initgroups,
  unix_getlogin,
  unix_getpwnam,
  unix_getgrnam,
  unix_getpwuid,
  unix_getgrgid,
  unix_inet_addr_of_string,
  unix_string_of_inet_addr,
  unix_socket,
  unix_socketpair,
  unix_bind,
  unix_connect,
  unix_listen,
  unix_shutdown,
  unix_getsockname,
  unix_getpeername,
  unix_gethostname,
  unix_gethostbyname,
  unix_gethostbyaddr,
  unix_getprotobyname,
  unix_getprotobynumber,
  unix_getservbyname,
  unix_getservbyport,
  unix_tcgetattr,
  unix_tcsetattr,
  unix_tcsendbreak,
  unix_tcdrain,
  unix_tcflush,
  unix_tcflow,
  unix_setsid,
  unix_getnameinfo,
  unix_getaddrinfo,
  unix_getsockopt,
  unix_setsockopt,
  unix_sendto,
  unix_send,
  unix_recvfrom,
  unix_recv,
  unix_single_write,
  unix_write,
  unix_read,
  set_digit_nat,
  mult_digit_nat,
  blit_nat,
  num_digits_nat,
  create_nat,
  div_digit_nat,
  square_nat,
  set_to_zero_nat,
  is_digit_zero,
  is_digit_int,
  nth_digit_nat,
  div_nat,
  add_nat,
  shift_right_nat,
  num_leading_zero_bits_in_digit,
  complement_nat,
  compare_nat,
  initialize_nat,
  lxor_digit_nat,
  lor_digit_nat,
  land_digit_nat,
  compare_digits_nat,
  shift_left_nat,
  mult_nat,
  sub_nat,
  decr_nat,
  incr_nat,
  is_digit_odd,
  is_digit_normalized,
  nth_digit_nat_native,
  set_digit_nat_native,
  coq_push_ra,
  coq_push_arguments,
  coq_push_val,
  coq_interprete_ml,
  coq_set_drawinstr,
  get_coq_transp_value,
  coq_set_transp_value,
  coq_push_vstack,
  coq_offset_tcode,
  coq_offset_closure,
  coq_makeaccu,
  realloc_coq_atom_tbl,
  get_coq_atom_tbl,
  coq_int_tcode,
  coq_offset,
  coq_closure_arity,
  coq_accucond,
  coq_is_accumulate_code,
  coq_kind_of_closure,
  coq_pushpop,
  init_coq_vm,
  accumulate_code,
  coq_tcode_of_code,
  coq_eval_tcode,
  get_coq_global_boxed,
  realloc_coq_global_boxed,
  get_coq_global_data,
  realloc_coq_global_data,
  coq_static_free,
  (primitive) 0 };
char * caml_names_of_builtin_cprim[] = {
  "caml_alloc_dummy",
  "caml_alloc_dummy_float",
  "caml_update_dummy",
  "caml_array_get_addr",
  "caml_array_get_float",
  "caml_array_get",
  "caml_array_set_addr",
  "caml_array_set_float",
  "caml_array_set",
  "caml_array_unsafe_get_float",
  "caml_array_unsafe_get",
  "caml_array_unsafe_set_addr",
  "caml_array_unsafe_set_float",
  "caml_array_unsafe_set",
  "caml_make_vect",
  "caml_make_array",
  "caml_compare",
  "caml_equal",
  "caml_notequal",
  "caml_lessthan",
  "caml_lessequal",
  "caml_greaterthan",
  "caml_greaterequal",
  "caml_output_value",
  "caml_output_value_to_string",
  "caml_output_value_to_buffer",
  "caml_format_float",
  "caml_float_of_string",
  "caml_int_of_float",
  "caml_float_of_int",
  "caml_neg_float",
  "caml_abs_float",
  "caml_add_float",
  "caml_sub_float",
  "caml_mul_float",
  "caml_div_float",
  "caml_exp_float",
  "caml_floor_float",
  "caml_fmod_float",
  "caml_frexp_float",
  "caml_ldexp_float",
  "caml_log_float",
  "caml_log10_float",
  "caml_modf_float",
  "caml_sqrt_float",
  "caml_power_float",
  "caml_sin_float",
  "caml_sinh_float",
  "caml_cos_float",
  "caml_cosh_float",
  "caml_tan_float",
  "caml_tanh_float",
  "caml_asin_float",
  "caml_acos_float",
  "caml_atan_float",
  "caml_atan2_float",
  "caml_ceil_float",
  "caml_expm1_float",
  "caml_log1p_float",
  "caml_eq_float",
  "caml_neq_float",
  "caml_le_float",
  "caml_lt_float",
  "caml_ge_float",
  "caml_gt_float",
  "caml_float_compare",
  "caml_classify_float",
  "caml_gc_stat",
  "caml_gc_quick_stat",
  "caml_gc_counters",
  "caml_gc_get",
  "caml_gc_set",
  "caml_gc_minor",
  "caml_gc_major",
  "caml_gc_full_major",
  "caml_gc_major_slice",
  "caml_gc_compaction",
  "caml_hash_univ_param",
  "caml_input_value",
  "caml_input_value_from_string",
  "caml_marshal_data_size",
  "caml_int_compare",
  "caml_int_of_string",
  "caml_format_int",
  "caml_int32_neg",
  "caml_int32_add",
  "caml_int32_sub",
  "caml_int32_mul",
  "caml_int32_div",
  "caml_int32_mod",
  "caml_int32_and",
  "caml_int32_or",
  "caml_int32_xor",
  "caml_int32_shift_left",
  "caml_int32_shift_right",
  "caml_int32_shift_right_unsigned",
  "caml_int32_of_int",
  "caml_int32_to_int",
  "caml_int32_of_float",
  "caml_int32_to_float",
  "caml_int32_compare",
  "caml_int32_format",
  "caml_int32_of_string",
  "caml_int32_bits_of_float",
  "caml_int32_float_of_bits",
  "caml_int64_neg",
  "caml_int64_add",
  "caml_int64_sub",
  "caml_int64_mul",
  "caml_int64_div",
  "caml_int64_mod",
  "caml_int64_and",
  "caml_int64_or",
  "caml_int64_xor",
  "caml_int64_shift_left",
  "caml_int64_shift_right",
  "caml_int64_shift_right_unsigned",
  "caml_int64_of_int",
  "caml_int64_to_int",
  "caml_int64_of_float",
  "caml_int64_to_float",
  "caml_int64_of_int32",
  "caml_int64_to_int32",
  "caml_int64_of_nativeint",
  "caml_int64_to_nativeint",
  "caml_int64_compare",
  "caml_int64_format",
  "caml_int64_of_string",
  "caml_int64_bits_of_float",
  "caml_int64_float_of_bits",
  "caml_nativeint_neg",
  "caml_nativeint_add",
  "caml_nativeint_sub",
  "caml_nativeint_mul",
  "caml_nativeint_div",
  "caml_nativeint_mod",
  "caml_nativeint_and",
  "caml_nativeint_or",
  "caml_nativeint_xor",
  "caml_nativeint_shift_left",
  "caml_nativeint_shift_right",
  "caml_nativeint_shift_right_unsigned",
  "caml_nativeint_of_int",
  "caml_nativeint_to_int",
  "caml_nativeint_of_float",
  "caml_nativeint_to_float",
  "caml_nativeint_of_int32",
  "caml_nativeint_to_int32",
  "caml_nativeint_compare",
  "caml_nativeint_format",
  "caml_nativeint_of_string",
  "caml_ml_open_descriptor_in",
  "caml_ml_open_descriptor_out",
  "caml_ml_out_channels_list",
  "caml_channel_descriptor",
  "caml_ml_close_channel",
  "caml_ml_channel_size",
  "caml_ml_channel_size_64",
  "caml_ml_set_binary_mode",
  "caml_ml_flush_partial",
  "caml_ml_flush",
  "caml_ml_output_char",
  "caml_ml_output_int",
  "caml_ml_output_partial",
  "caml_ml_output",
  "caml_ml_seek_out",
  "caml_ml_seek_out_64",
  "caml_ml_pos_out",
  "caml_ml_pos_out_64",
  "caml_ml_input_char",
  "caml_ml_input_int",
  "caml_ml_input",
  "caml_ml_seek_in",
  "caml_ml_seek_in_64",
  "caml_ml_pos_in",
  "caml_ml_pos_in_64",
  "caml_ml_input_scan_line",
  "caml_lex_engine",
  "caml_new_lex_engine",
  "caml_md5_string",
  "caml_md5_chan",
  "caml_get_global_data",
  "caml_get_section_table",
  "caml_reify_bytecode",
  "caml_realloc_global",
  "caml_get_current_environment",
  "caml_invoke_traced_function",
  "caml_static_alloc",
  "caml_static_free",
  "caml_static_release_bytecode",
  "caml_static_resize",
  "caml_obj_is_block",
  "caml_obj_tag",
  "caml_obj_set_tag",
  "caml_obj_block",
  "caml_obj_dup",
  "caml_obj_truncate",
  "caml_obj_add_offset",
  "caml_lazy_follow_forward",
  "caml_lazy_make_forward",
  "caml_get_public_method",
  "caml_parse_engine",
  "caml_set_parser_trace",
  "caml_install_signal_handler",
  "caml_ml_string_length",
  "caml_create_string",
  "caml_string_get",
  "caml_string_set",
  "caml_string_equal",
  "caml_string_notequal",
  "caml_string_compare",
  "caml_string_lessthan",
  "caml_string_lessequal",
  "caml_string_greaterthan",
  "caml_string_greaterequal",
  "caml_blit_string",
  "caml_fill_string",
  "caml_is_printable",
  "caml_bitvect_test",
  "caml_sys_exit",
  "caml_sys_open",
  "caml_sys_close",
  "caml_sys_file_exists",
  "caml_sys_is_directory",
  "caml_sys_remove",
  "caml_sys_rename",
  "caml_sys_chdir",
  "caml_sys_getcwd",
  "caml_sys_getenv",
  "caml_sys_get_argv",
  "caml_sys_system_command",
  "caml_sys_time",
  "caml_sys_random_seed",
  "caml_sys_get_config",
  "caml_sys_read_directory",
  "caml_terminfo_setup",
  "caml_terminfo_backup",
  "caml_terminfo_standout",
  "caml_terminfo_resume",
  "caml_register_named_value",
  "caml_weak_create",
  "caml_weak_set",
  "caml_weak_get",
  "caml_weak_get_copy",
  "caml_weak_check",
  "caml_weak_blit",
  "caml_final_register",
  "caml_final_release",
  "caml_ensure_stack_capacity",
  "caml_dynlink_open_lib",
  "caml_dynlink_close_lib",
  "caml_dynlink_lookup_symbol",
  "caml_dynlink_add_primitive",
  "caml_dynlink_get_current_libs",
  "caml_record_backtrace",
  "caml_backtrace_status",
  "caml_get_exception_backtrace",
  "re_replacement_text",
  "re_search_backward",
  "re_search_forward",
  "re_partial_match",
  "re_string_match",
  "unix_dup",
  "unix_close",
  "unix_waitpid",
  "unix_accept",
  "unix_error_message",
  "unix_environment",
  "unix_putenv",
  "unix_execv",
  "unix_execve",
  "unix_execvp",
  "unix_execvpe",
  "unix_fork",
  "unix_wait",
  "unix_getpid",
  "unix_getppid",
  "unix_nice",
  "unix_open",
  "unix_lseek",
  "unix_truncate",
  "unix_ftruncate",
  "unix_stat",
  "unix_lstat",
  "unix_fstat",
  "unix_isatty",
  "unix_lseek_64",
  "unix_truncate_64",
  "unix_ftruncate_64",
  "unix_stat_64",
  "unix_lstat_64",
  "unix_fstat_64",
  "unix_unlink",
  "unix_rename",
  "unix_link",
  "unix_chmod",
  "unix_fchmod",
  "unix_chown",
  "unix_fchown",
  "unix_umask",
  "unix_access",
  "unix_dup2",
  "unix_set_nonblock",
  "unix_clear_nonblock",
  "unix_set_close_on_exec",
  "unix_clear_close_on_exec",
  "unix_mkdir",
  "unix_rmdir",
  "unix_chdir",
  "unix_getcwd",
  "unix_chroot",
  "unix_opendir",
  "unix_readdir",
  "unix_rewinddir",
  "unix_closedir",
  "unix_pipe",
  "unix_mkfifo",
  "unix_symlink",
  "unix_readlink",
  "unix_select",
  "unix_lockf",
  "unix_kill",
  "unix_sigprocmask",
  "unix_sigpending",
  "unix_sigsuspend",
  "unix_time",
  "unix_gettimeofday",
  "unix_gmtime",
  "unix_localtime",
  "unix_mktime",
  "unix_alarm",
  "unix_sleep",
  "unix_times",
  "unix_utimes",
  "unix_getitimer",
  "unix_setitimer",
  "unix_getuid",
  "unix_geteuid",
  "unix_setuid",
  "unix_getgid",
  "unix_getegid",
  "unix_setgid",
  "unix_getgroups",
  "unix_setgroups",
  "unix_initgroups",
  "unix_getlogin",
  "unix_getpwnam",
  "unix_getgrnam",
  "unix_getpwuid",
  "unix_getgrgid",
  "unix_inet_addr_of_string",
  "unix_string_of_inet_addr",
  "unix_socket",
  "unix_socketpair",
  "unix_bind",
  "unix_connect",
  "unix_listen",
  "unix_shutdown",
  "unix_getsockname",
  "unix_getpeername",
  "unix_gethostname",
  "unix_gethostbyname",
  "unix_gethostbyaddr",
  "unix_getprotobyname",
  "unix_getprotobynumber",
  "unix_getservbyname",
  "unix_getservbyport",
  "unix_tcgetattr",
  "unix_tcsetattr",
  "unix_tcsendbreak",
  "unix_tcdrain",
  "unix_tcflush",
  "unix_tcflow",
  "unix_setsid",
  "unix_getnameinfo",
  "unix_getaddrinfo",
  "unix_getsockopt",
  "unix_setsockopt",
  "unix_sendto",
  "unix_send",
  "unix_recvfrom",
  "unix_recv",
  "unix_single_write",
  "unix_write",
  "unix_read",
  "set_digit_nat",
  "mult_digit_nat",
  "blit_nat",
  "num_digits_nat",
  "create_nat",
  "div_digit_nat",
  "square_nat",
  "set_to_zero_nat",
  "is_digit_zero",
  "is_digit_int",
  "nth_digit_nat",
  "div_nat",
  "add_nat",
  "shift_right_nat",
  "num_leading_zero_bits_in_digit",
  "complement_nat",
  "compare_nat",
  "initialize_nat",
  "lxor_digit_nat",
  "lor_digit_nat",
  "land_digit_nat",
  "compare_digits_nat",
  "shift_left_nat",
  "mult_nat",
  "sub_nat",
  "decr_nat",
  "incr_nat",
  "is_digit_odd",
  "is_digit_normalized",
  "nth_digit_nat_native",
  "set_digit_nat_native",
  "coq_push_ra",
  "coq_push_arguments",
  "coq_push_val",
  "coq_interprete_ml",
  "coq_set_drawinstr",
  "get_coq_transp_value",
  "coq_set_transp_value",
  "coq_push_vstack",
  "coq_offset_tcode",
  "coq_offset_closure",
  "coq_makeaccu",
  "realloc_coq_atom_tbl",
  "get_coq_atom_tbl",
  "coq_int_tcode",
  "coq_offset",
  "coq_closure_arity",
  "coq_accucond",
  "coq_is_accumulate_code",
  "coq_kind_of_closure",
  "coq_pushpop",
  "init_coq_vm",
  "accumulate_code",
  "coq_tcode_of_code",
  "coq_eval_tcode",
  "get_coq_global_boxed",
  "realloc_coq_global_boxed",
  "get_coq_global_data",
  "realloc_coq_global_data",
  "coq_static_free",
  (char *) 0 };
#ifdef __cplusplus
}
#endif

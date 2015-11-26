#include <aerospike_c_ruby.h>

// ----------------------------------------------------------------------------------
// Init
//
void Init_aerospike_c_ruby() {
  VALUE AerospikeC = rb_define_module("AerospikeC");

  rb_define_const(AerospikeC, "VERSION", rb_str_new2("1.0.0"));
  rb_define_const(AerospikeC, "C_CLIENT_VERSION", rb_str_new2("3.1.24"));

  init_aerospike_c_client(AerospikeC);
  init_aerospike_c_key(AerospikeC);
  init_aerospike_c_record(AerospikeC);
  init_aerospike_c_operation(AerospikeC);
  init_aerospike_c_index_task(AerospikeC);
}
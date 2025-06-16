.SILENT:
.PHONY: run 


build_grpc: 
	protoc -I ./ --cpp_out=./ --grpc_out=./ --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` calc.proto
run: 
	g++ main.cc -o out
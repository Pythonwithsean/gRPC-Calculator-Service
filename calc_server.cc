#include "calc.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <memory>

class CalcServiceImpl final : public Calc::Service
{

	grpc::Status Add(grpc::ServerContext *context, const Ops *req, Result *res) override
	{
		res->set_result(req->a() + req->b());
		return grpc::Status::OK;
	}

	grpc::Status Sub(grpc::ServerContext *content, const Ops *req, Result *res) override
	{
		res->set_result(req->a() - req->b());
		return grpc::Status::OK;
	}
};

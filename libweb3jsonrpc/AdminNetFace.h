/**
 * This file is generated by jsonrpcstub, DO NOT CHANGE IT MANUALLY!
 */

#ifndef JSONRPC_CPP_STUB_DEV_RPC_ADMINNETFACE_H_
#define JSONRPC_CPP_STUB_DEV_RPC_ADMINNETFACE_H_

#include "ModularServer.h"
#include "iostream"
namespace dev {
    namespace rpc {
        class AdminNetFace : public ServerInterface<AdminNetFace>
        {
            public:
                AdminNetFace()
                {
                    this->bindAndAddMethod(jsonrpc::Procedure("admin_net_connect", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_BOOLEAN, "param1",jsonrpc::JSON_STRING,"param2",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminNetFace::admin_net_connectI);
                    this->bindAndAddMethod(jsonrpc::Procedure("admin_net_peers", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_ARRAY, "param1",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminNetFace::admin_net_peersI);
                    this->bindAndAddMethod(jsonrpc::Procedure("admin_net_nodeInfo", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminNetFace::admin_net_nodeInfoI);
                    this->bindAndAddMethod(jsonrpc::Procedure("admin_nodeInfo", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT,  NULL), &dev::rpc::AdminNetFace::admin_nodeInfoI);
                    this->bindAndAddMethod(jsonrpc::Procedure("admin_peers", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT,  NULL), &dev::rpc::AdminNetFace::admin_peersI);
                    this->bindAndAddMethod(jsonrpc::Procedure("admin_addPeer", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_BOOLEAN, "param1",jsonrpc::JSON_STRING,"param2",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminNetFace::admin_addPeerI);
                    this->bindAndAddMethod(jsonrpc::Procedure("admin_addYapie", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_BOOLEAN, "param1",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminNetFace::admin_addYapieI);
                }

                inline virtual void admin_net_connectI(const Json::Value &request, Json::Value &response)
                {
                    /// request[1u].asString() 是添加的password字段
                    response = this->admin_net_connect(request[0u].asString(), request[1u].asString(),request[2u].asString());
                }
                inline virtual void admin_net_peersI(const Json::Value &request, Json::Value &response)
                {
                    response = this->admin_net_peers(request[0u].asString());
                }
                inline virtual void admin_net_nodeInfoI(const Json::Value &request, Json::Value &response)
                {
                    response = this->admin_net_nodeInfo(request[0u].asString());
                }
                inline virtual void admin_nodeInfoI(const Json::Value &request, Json::Value &response)
                {
                    (void)request;
                    response = this->admin_nodeInfo();
                }
                inline virtual void admin_peersI(const Json::Value &request, Json::Value &response)
                {
                    (void)request;
                    response = this->admin_peers();
                }
                inline virtual void admin_addPeerI(const Json::Value &request, Json::Value &response)
                {
                    std::cout<<"in addPeerI"<<std::endl;
                    response = this->admin_addPeer(request[0u].asString(),request[1u].asString());
                }
                inline virtual void admin_addYapieI(const Json::Value &request, Json::Value &response)
                {
                    response = this->admin_addYapie(request[0u].asString());
                }
                
                virtual bool admin_net_connect(const std::string& param1, const std::string& param2 ,const std::string& param3) = 0;
                virtual Json::Value admin_net_peers(const std::string& param1) = 0;
                virtual Json::Value admin_net_nodeInfo(const std::string& param1) = 0;
                virtual Json::Value admin_nodeInfo() = 0;
                virtual Json::Value admin_peers() = 0;
                virtual bool admin_addPeer(const std::string& param1,const std::string & param2) = 0;
                virtual Json::Value admin_addYapie(const std::string& param1) = 0; 
        };

    }
}
#endif //JSONRPC_CPP_STUB_DEV_RPC_ADMINNETFACE_H_

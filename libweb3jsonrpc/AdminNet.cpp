#include "AdminNet.h"
#include "JsonHelper.h"
#include "SessionManager.h"
#include <jsonrpccpp/common/exception.h>
#include <libdevcore/CommonJS.h>
#include <libethcore/Common.h>
#include <libwebthree/WebThree.h>
#include <checkPermission.h>
using namespace std;
using namespace dev;
using namespace dev::rpc;

AdminNet::AdminNet(NetworkFace& _network, SessionManager& _sm) : m_network(_network), m_sm(_sm) {}

bool AdminNet::admin_net_connect(
    std::string const& _node, std::string const& password, std::string const& _session)
{
    RPC_ADMIN;

    return admin_addPeer(_node, password);
}

Json::Value AdminNet::admin_net_peers(std::string const& _session)
{
    RPC_ADMIN;
    return admin_peers();
}

Json::Value AdminNet::admin_net_nodeInfo(std::string const& _session)
{
    RPC_ADMIN;
    Json::Value ret;
    p2p::NodeInfo i = m_network.nodeInfo();
    ret["name"] = i.version;
    ret["port"] = i.port;
    ret["address"] = i.address;
    ret["listenAddr"] = i.address + ":" + toString(i.port);
    ret["id"] = i.id.hex();
    ret["enode"] = i.enode();
    return ret;
}

Json::Value AdminNet::admin_nodeInfo()
{
    Json::Value ret;
    p2p::NodeInfo i = m_network.nodeInfo();
    ret["name"] = i.version;
    ret["ports"] = Json::objectValue;
    // Both ports are equal as of 2016-02-04, migt change later
    ret["ports"]["discovery"] = i.port;
    ret["ports"]["listener"] = i.port;
    ret["ip"] = i.address;
    ret["listenAddr"] = i.address + ":" + toString(i.port);
    ret["id"] = i.id.hex();
    ret["enode"] = i.enode();
    ret["protocols"] = Json::objectValue;
    ret["protocols"]["eth"] = Json::objectValue;  //@todo fill with information
    return ret;
}

Json::Value AdminNet::admin_peers()
{
    Json::Value ret;
    for (p2p::PeerSessionInfo const& peer : m_network.peers())
        ret.append(toJson(peer));
    return ret;
}


// virtual bool admin_addPeer(std::string const& _node,std::string const& password) override;

bool AdminNet::admin_addPeer(std::string const& _node, std::string const& password)
{
    std::cout << "in addPeer" << std::endl;
    bool result = false;
    checkPermission checker;
    string md5 = checker.generateMD5()
    if (checker.check(password))
    {
        m_network.addPeer(p2p::NodeSpec(_node), p2p::PeerType::Required);
        result = true;
    }
    return result;
}

Json::Value AdminNet::admin_addYapie(std::string const& userName)
{
	Json::Value ret;
	ret["name"] = userName;
	ret["uuid"] = "000001";
	return ret;
}

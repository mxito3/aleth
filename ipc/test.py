from web3 import Web3,HTTPProvider
from web3.middleware import geth_poa_middleware


import json
class ipc(object):
    def __init__(self):
        self.web3 = Web3(Web3.IPCProvider('/home/yapie/github/aleth/private/testData/geth.ipc'))
        self.web3.middleware_stack.inject(geth_poa_middleware, layer=0)
        assert self.web3.isConnected(),'connect fail'
    def getCoinbase(self):
        print(str(self.web3.admin.nodeInfo))
        
    def add(self,url,password):
        # test()
        return self.web3.admin.addPeer(url,password)
    def getPeer(self):
        return self.web3.admin.peers
    def addYapie(self,userName):
        return self.web3.admin.addYapie(userName)
if __name__ == "__main__":
    testIPC  = ipc()
    address = "enode://64c21e7bdc4b4bce6b3ca5b60fc4426af5ad329937bd0bbf26cc57ef36daf581bf9f58ccea206b742e7cabea1c6054dc015f5bf70016a02488ddce35ec64ed8e@152.0.0.116:30303"
    password = "123456"
    print(testIPC.add(address,password))
    # print(testIPC.getPeer())
    # print(testIPC.addYapie("yapie"))

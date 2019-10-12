//
//  MasterServer.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-10-02.
//

#ifndef MasterServer_hpp
#define MasterServer_hpp

#include "../../../Common/Messages/messages.hpp"
#include "../../../Common/CommunicationEngine/Server.hpp"
#include "../../../Common/CommunicationEngine/Exchanges/Datagrams/Ping.hpp"

#include "../../LayoutEngine/LayoutEngine.hpp"


class Socket;

class MasterServer: Server, Ping {
public:

	MasterServer(const Endpoint::Type &aType):
		Server(aType) {
		open();
		advertise();
	}

	/// Handle to the layout engine
	LayoutEngine * layoutEngine = nullptr;

protected:
	void onClient(Socket * newSocket) override;

	void onSocketClosed(Socket * closedSocket) override;

private:

	void onDatagram(messages::Datagram * datagram, Socket * socket);
};

#endif /* MasterServer_hpp */
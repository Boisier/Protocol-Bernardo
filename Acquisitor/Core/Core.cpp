//
//  Core.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-20.
//

#include "Core.hpp"

#include "../libraries.hpp"

#include "../../Common/Utils/Log.hpp"
#include "../../Common/CommunicationEngine/CommunicationEngine.hpp"
#include "../../Common/CommunicationEngine/Discovery/Advertiser.hpp"

#include "AcquisitorServer.hpp"

#include <boost/bind.hpp>
#include <pthread.h>

void Core::init() {
	// Name our main thread
	pthread_setname_np("pb.acquisitor.main");

	// Set up the acquisitor server
	LOG_INFO("Starting up the acquisitor server");
	_server = new AcquisitorServer(Endpoint::Type::acquisitor);

	// Setup the Pose estimation engine
	_poseEngine.onBody = [&] (const Body * body) {
		onBody(body);
	};
	
	_poseEngine.start();

}

void Core::run() {
	while(true) {
		std::string input;
		std::cin >> input;
	}
}

void Core::onBody(const Body * body) {
	
}

Core::~Core() {
//	delete _poseEngine;
	delete _server;
}

// MARK: - Communication
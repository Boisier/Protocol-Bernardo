
//
//  getOutput.cpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-28.
//

#include "Output.hpp"

#include <iostream>

#include "B-100/S-100-00.hpp"
#include "B-102/S-102-00.hpp"

Output * Output::get(const unsigned int id) {
	switch (id) {
		case 10000:
			return new S10000();
		case 10200:
			return new S10200();
		default:
			std::cout << "No output " << id << std::endl;
			return nullptr;
	}
}

//
//  S-815-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_815_00_hpp
#define S_815_00_hpp

#include "../../Output.hpp"

class S81500 : public Output {
public:

	S81500() : Output(81500,	// Output ID
		false,	// Is tree end ?
		816,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Cela nous ram�ne tout de m�me au questionnement de d�part. On ne sait toujours pas si les personnes pr�sentes savent ce qui se d�roule ici."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_815_00_hpp */

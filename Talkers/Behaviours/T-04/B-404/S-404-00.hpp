//
//  S-404-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_404_00_hpp
#define S_404_00_hpp

#include "../../Output.hpp"

class S40400 : public Output {
public:

	S40400() : Output(40400,	// Output ID
		false,	// Is tree end ?
		405,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"M�me en prenant en compte un seuil de tol�rance, comment savoir si nos op�rations ne causeront pas d'erreurs irr�parables ?",
		"Comment savoir si nous faison le bon choix en faisant confiance � nos r�sultats, si ceux-ci sont sensibles � une marge d'erreur ?"
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_404_00_hpp */

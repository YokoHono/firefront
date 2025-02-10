#ifndef TENPERCENT_H_
#define TENPERCENT_H_

#include "PropagationModel.h"
#include "FireDomain.h"

namespace libforefire {

class TroisPourcent: public libforefire::PropagationModel {

	/*! name the model */
	static const string name;

	/*! boolean for initialization */
	static int isInitialized;

	/*! properties needed by the model */
	size_t effectiveSlope;
	size_t normalWind;

	/*! coefficients needed by the model */
	double R0;
	double windFactor;
	double slopeFactor;

	/*! local variables */

	/*! result of the model */
	double getSpeed(double*);

public:

	TroisPourcent(const int& = 0, DataBroker* db=0);
	virtual ~TroisPourcent();

	string getName();

};

PropagationModel* getTroisPourcentModel(const int& = 0, DataBroker* = 0);

}

#endif /* TROISPOURCENT_H_ */

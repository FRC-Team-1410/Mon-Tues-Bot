#ifndef FIRE_H
#define FIRE_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author zeitgeist
 */
class Fire: public CommandBase {
public:
	Fire();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

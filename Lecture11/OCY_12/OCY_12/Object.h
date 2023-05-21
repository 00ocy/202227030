#pragma once

class Object
{

public:
	Object() {}
	virtual ~Object() {}

	virtual void Start() {}
	virtual void Update() {}
	virtual void Render() {}

private:

};
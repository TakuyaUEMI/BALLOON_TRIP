#pragma once
class CONTAINER
{
private:
	struct DATA {

	};
	DATA Data;
public:
	CONTAINER();
	~CONTAINER();
	void load();
		void setData();

		void loadGraphic();
	const DATA& data() { return Data; }
};


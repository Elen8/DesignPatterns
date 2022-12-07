#include <iostream>
#include <memory>
class HomeWork
{
public:
	void DesignPatternsHomework();
	void OOPHomework();
	void ScriptingLanguagesHomework();
};

class WeekDays
{
public:
	void CheckOutlook();
	void CheckTeams();
};

class AdditionalWorks
{
public:
	void WeeklyReport();
	void Timesheet();
	void Shopping();
};

class Friday //facade
{
public:
	Friday()
	{
		hw = std::make_unique<HomeWork>();
		wd = std::make_unique<WeekDays>();
		aw = std::make_unique<AdditionalWorks>();
	}

	void FridayToDo()
	{
		hw->ScriptingLanguagesHomework();
		wd->CheckOutlook();
		wd->CheckTeams();
		aw->Timesheet();
		aw->WeeklyReport();
	}

private:
	std::unique_ptr<HomeWork> hw;
	std::unique_ptr<WeekDays> wd;
	std::unique_ptr<AdditionalWorks> aw;
};

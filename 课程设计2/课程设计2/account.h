#pragma once
class Account {
public:
	Account();
	bool signin(void);
	bool login(void) const;
private:
	char accountnum[8];
	char password[8];
};
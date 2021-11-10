#ifndef CHINESEREMINDER_H_INCLUDED
#define CHINESEREMINDER_H_INCLUDED

int chineseReminderUsingInverse(int numberOfEquations, const int* residue, const int* module);
int chineseReminderUsingMainEquation(int numberOfEquations, const int* residue, const int* module);

void testChineseReminder();

#endif // CHINESEREMINDER_H_INCLUDED

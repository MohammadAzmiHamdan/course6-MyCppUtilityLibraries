#pragma once

#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <ctime>
#include <string>

namespace MyUtilityDateLib {


    struct stDate {
        short Year;
        short Month;
        short Day;
    };

    struct stPeriod {
        stDate StartDate;
        stDate EndDate;
    };

    enum eDateCompare { Equal = 0, After = 1, Before = -1 };

    short ReadYear() {
        short year;
        std::cout << " Please enter a year?";
        std::cin >> year;
        return year;
    }

    short ReadMonth() {
        short Month;
        std::cout << " Please enter a Month?";
        std::cin >> Month;
        return Month;
    }

    short ReadDay() {
        short Day;
        std::cout << " Please enter a Day?";
        std::cin >> Day;
        return Day;
    }

    bool IsLeapYear(short year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    short NumberOFDaysInAYear(short year) {
        return IsLeapYear(year) ? 366 : 365;
    }

    int NumberOfHoursInAYear(short Year) {
        return 24 * NumberOFDaysInAYear(Year);
    }

    int NumberOfMinutesInAYear(short Year) {
        return 60 * NumberOfHoursInAYear(Year);
    }

    int NumberOfSecondsInAYear(short Year) {
        return 60 * NumberOfMinutesInAYear(Year);
    }

    short NumberOfDaysInMonth(short month, short year) {
        if (month < 1 || month > 12)
            return 0;
        short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return month == 2 ? (IsLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
    }

    int NumberOfHoursInMonth(short month, short year) {
        return 24 * NumberOfDaysInMonth(month, year);
    }

    int NumberOfMinutesInMonth(short month, short year) {
        return 60 * NumberOfHoursInMonth(month, year);
    }

    int NumberOfSecondsInMonth(short month, short year) {
        return 60 * NumberOfMinutesInMonth(month, year);
    }

    short DayOfWeekOrder(short day, short month, short year) {
        short a, y, m;
        a = (14 - month) / 12;
        y = year - a;
        m = month + 12 * a - 2;
        return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    short DayOfWeekOrder(stDate Date) {
        return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
    }

    std::string DayShortName(short DayOfWeekOrder) {
        std::string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
        return arrDayNames[DayOfWeekOrder];
    }

    std::string MonthShortName(short MonthNumber) {
        std::string Months[12] = {
            "Jan", "Feb", "Mar",
            "Apr", "May", "Jun",
            "Jul", "Aug", "Sep",
            "Oct", "Nov", "Dec"
        };
        return Months[MonthNumber - 1];
    }

    void PrintMonthCalendar(short Month, short Year) {
        short current = DayOfWeekOrder(1, Month, Year);
        short NumberOfDays = NumberOfDaysInMonth(Month, Year);

        printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        short i;
        for (i = 0; i < current; i++) {
            printf("     ");
        }
        for (short j = 1; j <= NumberOfDays; j++) {
            printf("%5d", j);
            if (++i == 7) {
                i = 0;
                printf("\n");
            }
        }
        printf("\n __________________________________\n");
    }

    void PrintYearCalenar(short Year) {
        printf("\n __________________________________\n\n");
        printf("            Calendar - %d\n", Year);
        printf(" __________________________________\n");
        for (short i = 1; i <= 12; i++) {
            PrintMonthCalendar(i, Year);
        }
    }

    short NumberOfDaysFromTheBeginingOfTheYear(short day, short month, short year) {
        short DayNumbers = 0;
        for (short i = 1; i < month; i++) {
            DayNumbers += NumberOfDaysInMonth(i, year);
        }
        DayNumbers += day;
        return DayNumbers;
    }

    stDate ReadFullDate() {
        stDate sDate;
        std::cout << " Please enter a year?";
        std::cin >> sDate.Year;
        std::cout << " Please enter a Month?";
        std::cin >> sDate.Month;
        std::cout << " Please enter a Day?";
        std::cin >> sDate.Day;
        return sDate;
    }

    stDate GetDateFromDayOrderInYear(short DayOrderInYear, short Year) {
        stDate sDate;
        short RamainingDays = DayOrderInYear;
        sDate.Month = 1;
        sDate.Year = Year;
        short MonthDays;
        while (true) {
            MonthDays = NumberOfDaysInMonth(sDate.Month, Year);
            if (RamainingDays > MonthDays) {
                RamainingDays -= MonthDays;
                sDate.Month++;
            }
            else {
                sDate.Day = RamainingDays;
                break;
            }
        }
        return sDate;
    }

    stDate DateAddDays(short Days, stDate sDate) {
        short RamainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(sDate.Day, sDate.Month, sDate.Year);
        short MonthDays;
        sDate.Month = 1;
        while (true) {
            MonthDays = NumberOfDaysInMonth(sDate.Month, sDate.Year);
            if (RamainingDays > MonthDays) {
                sDate.Month++;
                RamainingDays -= MonthDays;
                if (sDate.Month > 12) {
                    sDate.Month = 1;
                    sDate.Year++;
                }
            }
            else {
                sDate.Day = RamainingDays;
                break;
            }
        }
        return sDate;
    }

    short ReadDaysToAdd() {
        short Days;
        std::cout << "\nHow many days to add? ";
        std::cin >> Days;
        return Days;
    }

    bool IsDate1BeforeDate2(stDate sDate1, stDate sDate2) {
        return (sDate1.Year < sDate2.Year) ? true : (sDate1.Year == sDate2.Year ?
            (sDate1.Month < sDate2.Month) ? true : (sDate1.Month == sDate2.Month ?
                sDate1.Day < sDate2.Day : false) : false);
    }

    bool IsDate1EqualDate2(stDate sDate1, stDate sDate2) {
        return (sDate1.Year == sDate2.Year) && (sDate1.Month == sDate2.Month) && (sDate1.Day == sDate2.Day);
    }

    bool IsLastDayInAMonth(stDate sDate) {
        return sDate.Day == NumberOfDaysInMonth(sDate.Month, sDate.Year);
    }

    bool IsLastMonthInAYear(stDate sDate) {
        return sDate.Month == 12;
    }

    stDate IncreaseDateByOneDay(stDate sDate) {
        if (IsLastDayInAMonth(sDate)) {
            if (IsLastMonthInAYear(sDate)) {
                sDate.Day = 1;
                sDate.Month = 1;
                sDate.Year++;
            }
            else {
                sDate.Day = 1;
                sDate.Month++;
            }
        }
        else {
            sDate.Day++;
        }
        return sDate;
    }

    void SwapDates(stDate& Date1, stDate& Date2) {
        stDate TempDate;
        TempDate.Year = Date1.Year;
        TempDate.Month = Date1.Month;
        TempDate.Day = Date1.Day;
        Date1.Year = Date2.Year;
        Date1.Month = Date2.Month;
        Date1.Day = Date2.Day;
        Date2.Year = TempDate.Year;
        Date2.Month = TempDate.Month;
        Date2.Day = TempDate.Day;
    }

    int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false) {
        int Days = 0;
        short SwapFlagValue = 1;
        if (!IsDate1BeforeDate2(Date1, Date2)) {
            SwapFlagValue = -1;
            SwapDates(Date1, Date2);
        }
        while (IsDate1BeforeDate2(Date1, Date2)) {
            Days++;
            Date1 = IncreaseDateByOneDay(Date1);
        }
        return IncludeEndDay ? (++Days) * SwapFlagValue : Days * SwapFlagValue;
    }

    stDate GetSystemTime() {
        stDate sDate;
        time_t t = time(0);
        tm* now = localtime(&t);
        sDate.Year = now->tm_year + 1900;
        sDate.Month = now->tm_mon + 1;
        sDate.Day = now->tm_mday;
        return sDate;
    }

    stDate IncreasDateByXDays(short Day, stDate Date) {
        for (short i = 0; i < Day; i++) {
            Date = IncreaseDateByOneDay(Date);
        }
        return Date;
    }

    stDate IncreaseDateByOneWeek(stDate Date) {
        return IncreasDateByXDays(7, Date);
    }

    stDate IncreaseDateByXWeeks(short Weeks, stDate Date) {
        for (short i = 0; i < Weeks; i++) {
            Date = IncreaseDateByOneWeek(Date);
        }
        return Date;
    }

    stDate IncreaseDateByOneMonth(stDate Date) {
        if (IsLastMonthInAYear(Date)) {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else {
            Date.Month++;
        }
        short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
        if (NumberOfDaysInCurrentMonth < Date.Day) {
            Date.Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }

    stDate IncreaseDateByXMonths(stDate Date, short Months) {
        for (short i = 1; i <= Months; i++) {
            Date = IncreaseDateByOneMonth(Date);
        }
        return Date;
    }

    stDate IncreaseDateByOneYear(stDate Date) {
        Date.Year++;
        return Date;
    }

    stDate IncreaseDateByXYears(stDate Date, short Years) {
        for (short i = 1; i <= Years; i++) {
            Date = IncreaseDateByOneYear(Date);
        }
        return Date;
    }

    stDate IncreaseDateByXYearsFaster(stDate Date, short Years) {
        Date.Year += Years;
        return Date;
    }

    stDate IncreaseDateByOneDecade(stDate Date) {
        Date.Year += 10;
        return Date;
    }

    stDate IncreaseDateByXDecades(stDate Date, short Deacdes) {
        for (short i = 1; i <= Deacdes; i++) {
            Date = IncreaseDateByOneDecade(Date);
        }
        return Date;
    }

    stDate IncreaseDateByXDecadesFaster(stDate Date, short Deacdes) {
        Date.Year += 10 * Deacdes;
        return Date;
    }

    stDate IncreaseDateByOneCentury(stDate Date) {
        Date.Year += 100;
        return Date;
    }

    stDate IncreaseDateByOneMillennium(stDate Date) {
        Date.Year += 1000;
        return Date;
    }

    stDate DecreaseDateByOneDay(stDate Date) {
        if (Date.Day == 1) {
            if (Date.Month == 1) {
                Date.Year--;
                Date.Month = 12;
                Date.Day = 31;
            }
            else {
                Date.Month--;
                Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
            }
        }
        else {
            Date.Day--;
        }
        return Date;
    }

    stDate DecreaseDateByXDays(stDate Date, short Days) {
        for (short i = 1; i <= Days; i++) {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }

    stDate DecreaseDateByOneWeek(stDate Date) {
        for (short i = 1; i <= 7; i++) {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }

    stDate DecreaseDateByXWeeks(stDate Date, short Weeks) {
        for (short i = 1; i <= Weeks; i++) {
            Date = DecreaseDateByOneWeek(Date);
        }
        return Date;
    }

    stDate DecreaseDateByOneMonth(stDate Date) {
        if (Date.Month == 1) {
            Date.Year--;
            Date.Month = 12;
        }
        else {
            Date.Month--;
        }
        short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
        if (Date.Day > NumberOfDaysInCurrentMonth) {
            Date.Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }

    stDate DecreaseDateByXMonths(stDate Date, short Months) {
        for (short i = 1; i <= Months; i++) {
            Date = DecreaseDateByOneMonth(Date);
        }
        return Date;
    }

    stDate DecreaseDateByOneYear(stDate Date) {
        Date.Year--;
        short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
        if (Date.Day > NumberOfDaysInCurrentMonth) {
            Date.Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }

    stDate DecreaseDateByXYears(stDate Date, short Years) {
        for (short i = 1; i <= Years; i++) {
            Date = DecreaseDateByOneYear(Date);
        }
        return Date;
    }

    stDate DecreaseDateByXYearsFaster(stDate Date, short Years) {
        Date.Year -= Years;
        return Date;
    }

    stDate DecreaseDateByOneDecade(stDate Date) {
        Date.Year -= 10;
        short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
        if (Date.Day > NumberOfDaysInCurrentMonth) {
            Date.Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }

    stDate DecreaseDateByXDecades(stDate Date, short Decades) {
        for (short i = 1; i <= Decades; i++) {
            Date = DecreaseDateByOneDecade(Date);
        }
        return Date;
    }

    stDate DecreaseDateByXDecadesFaster(stDate Date, short Decades) {
        Date.Year -= Decades * 10;
        return Date;
    }

    stDate DecreaseDateByOneCentury(stDate Date) {
        Date.Year -= 100;
        return Date;
    }

    stDate DecreaseDateByOneMillennium(stDate Date) {
        Date.Year -= 1000;
        return Date;
    }

    bool IsEndOfWeek(stDate Date) {
        return DayOfWeekOrder(Date) == 6;
    }

    bool IsWeekEnd(stDate Date) {
        short DayIndex = DayOfWeekOrder(Date);
        return DayIndex == 6 || DayIndex == 5;
    }

    bool IsBusinessDay(stDate Date) {
        return !IsWeekEnd(Date);
    }

    short DaysUntilTheEndOfWeek(stDate Date) {
        return 6 - DayOfWeekOrder(Date);
    }

    short DaysUntilTheEndOfMonth(stDate Date1) {
        stDate EndOfMonthDate;
        EndOfMonthDate.Day = NumberOfDaysInMonth(Date1.Month, Date1.Year);
        EndOfMonthDate.Month = Date1.Month;
        EndOfMonthDate.Year = Date1.Year;
        return GetDifferenceInDays(Date1, EndOfMonthDate, true);
    }

    short DaysUntilTheEndOfYear(stDate Date1) {
        stDate EndOfYearDate;
        EndOfYearDate.Day = 31;
        EndOfYearDate.Month = 12;
        EndOfYearDate.Year = Date1.Year;
        return GetDifferenceInDays(Date1, EndOfYearDate, true);
    }

    short CalculateVacationDays(stDate DateFrom, stDate DateTo) {
        short DaysCount = 0;
        while (IsDate1BeforeDate2(DateFrom, DateTo)) {
            if (IsBusinessDay(DateFrom))
                DaysCount++;
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }
        return DaysCount;
    }

    stDate CalculateVacationReturnDate(stDate DateFrom, short VicationDays) {
        while (IsWeekEnd(DateFrom)) {
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }
        short WeekEndCounter = 0;
        for (short i = 1; i <= VicationDays + WeekEndCounter; i++) {
            if (IsWeekEnd(DateFrom))
                WeekEndCounter++;
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }
        while (IsWeekEnd(DateFrom)) {
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }
        return DateFrom;
    }

    bool IsDate1AfterDate2(stDate Date1, stDate Date2) {
        return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
    }

    eDateCompare CompareDates(stDate Date1, stDate Date2) {
        if (IsDate1BeforeDate2(Date1, Date2))
            return eDateCompare::Before;
        if (IsDate1EqualDate2(Date1, Date2))
            return eDateCompare::Equal;
        return eDateCompare::After;
    }

    bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2) {
        if (CompareDates(Period1.StartDate, Period1.EndDate) == eDateCompare::After ||
            CompareDates(Period1.EndDate, Period1.StartDate) == eDateCompare::Before)
            return false;
        else
            return true;
    }

    short ReadVacationDays() {
        short Days;
        std::cout << "\nPlease enter vacation days? ";
        std::cin >> Days;
        return Days;
    }

    stPeriod ReadPeriod() {
        stPeriod Period;
        std::cout << "\nEnter Start Date:\n";
        Period.StartDate = ReadFullDate();
        std::cout << "\nEnter End Date:\n";
        Period.EndDate = ReadFullDate();
        return Period;
    }

    int PeriodLengthInDays(stPeriod Period, bool IncludeEndDate = false) {
        return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
    }

    bool IsDateInPeriod(stDate Date, stPeriod Period) {
        return !(CompareDates(Date, Period.StartDate) == eDateCompare::Before
            || CompareDates(Date, Period.EndDate) == eDateCompare::After);
    }

    int CountOverlapDays(stPeriod Period1, stPeriod Period2) {
        int Period1Length = PeriodLengthInDays(Period1, true);
        int Period2Length = PeriodLengthInDays(Period2, true);

        if (!IsOverlapPeriods(Period1, Period2))
            return 0;

        int OverLapDays = 0;
        if (Period1Length < Period2Length) {
            while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate)) {
                if (IsDateInPeriod(Period1.StartDate, Period2))
                    OverLapDays++;
                Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
            }
        }
        else {
            while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate)) {
                if (IsDateInPeriod(Period2.StartDate, Period1))
                    OverLapDays++;
                Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
            }
        }
        return OverLapDays;
    }

    bool IsValidDate(stDate Date) {
        if (Date.Month < 1 || Date.Month > 12 || Date.Year < 0)
            return false;
        if (Date.Day < 1 || Date.Day > 31)
            return false;
        if (Date.Month == 2) {
            if (IsLeapYear(Date.Year)) {
                if (Date.Day > 29)
                    return false;
            }
            else {
                if (Date.Day > 28)
                    return false;
            }
        }
        short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
        if (Date.Day > NumberOfDaysInCurrentMonth)
            return false;
        return true;
    }

    std::vector<std::string> SplitString(std::string S1, std::string Delim) {
        std::vector<std::string> vString;
        short pos = 0;
        std::string sWord;
        while ((pos = S1.find(Delim)) != std::string::npos) {
            sWord = S1.substr(0, pos);
            if (sWord != "") {
                vString.push_back(sWord);
            }
            S1.erase(0, pos + Delim.length());
        }
        if (S1 != "") {
            vString.push_back(S1);
        }
        return vString;
    }

    stDate StringToDate(std::string StringDate) {
        stDate Date;
        std::vector<std::string> vDate;
        vDate = SplitString(StringDate, "/");
        Date.Day = stoi(vDate[0]);
        Date.Month = stoi(vDate[1]);
        Date.Year = stoi(vDate[2]);
        return Date;
    }

    std::string DateToString(stDate Date) {
        return std::to_string(Date.Day) + "/" + std::to_string(Date.Month) + "/" + std::to_string(Date.Year);
    }

    std::string ReadStringDate(std::string Message) {
        std::string DateString;
        std::cout << Message;
        std::getline(std::cin >> std::ws, DateString);
        return DateString;
    }

    std::string ReplaceWordInString(std::string S1, std::string StringToReplace, std::string sRepalceTo) {
        short pos = S1.find(StringToReplace);
        while (pos != std::string::npos) {
            S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
            pos = S1.find(StringToReplace);
        }
        return S1;
    }

    std::string FormateDate(stDate Date, std::string DateFormat = "dd/mm/yyyy") {
        std::string FormattedDateString = "";
        FormattedDateString = ReplaceWordInString(DateFormat, "dd", std::to_string(Date.Day));
        FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", std::to_string(Date.Month));
        FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", std::to_string(Date.Year));
        return FormattedDateString;
    }

} // namespace MyUtilityDateLib
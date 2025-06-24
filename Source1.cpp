bool check_eng_extra(const wstring& s) {
    static const map<wstring, int> mon_en = {
        {L"january",1},{L"february",2},{L"march",3},{L"april",4},
        {L"may",5},{L"june",6},{L"july",7},{L"august",8},
        {L"september",9},{L"october",10},{L"november",11},{L"december",12},
        {L"jan",1},{L"feb",2},{L"mar",3},{L"apr",4},
        {L"may",5},{L"jun",6},{L"jul",7},{L"aug",8},
        {L"sep",9},{L"oct",10},{L"nov",11},{L"dec",12}
    };
    std::wistringstream ss(s);
    wstring part1, part2, part3;
    if (!(ss >> part1 >> part2 >> part3)) return false;

    // 1. Day MonthName Year
    wstring mname = part2;
    std::transform(mname.begin(), mname.end(), mname.begin(), ::towlower);
    if (is_int_in_range(part1, 1, 31) && mon_en.count(mname) && is_int_in_range(part3, 0, 9999)) {
        int d = std::stoi(part1), m = mon_en.at(mname), y = std::stoi(part3);
        if (d <= days_in_month(m, y)) return true;
    }
    // 2. MonthName Day Year (например, "June 20 2011")
    mname = part1;
    std::transform(mname.begin(), mname.end(), mname.begin(), ::towlower);
    if (mon_en.count(mname) && is_int_in_range(part2, 1, 31) && is_int_in_range(part3, 0, 9999)) {
        int m = mon_en.at(mname), d = std::stoi(part2), y = std::stoi(part3);
        if (d <= days_in_month(m, y)) return true;
    }
    return false;
}

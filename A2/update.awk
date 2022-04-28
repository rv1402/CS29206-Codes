
function ndays(date1, date2){
    gsub(/-/, " ", date1)
    gsub(/-/, " ", date2)
    date1 = date1" 0 0 0"
    date2 = date2" 0 0 0"
    t1 = mktime(date1)
    t2 = mktime(date2)

    if(t2 >= t1){
        num = (t2-t1)/3600/24
    }
    else{
        num = (t1-t2)/3600/24
    }
    return num
}

function getyear(date){
    if(date == "")
        return 0
    return substr(date, 7, 4)
}

function round(n){
    if(n - int(n) >= 0.5){
        return (int(n)+1)
    }
    else{
        return int(n)
    }
}

BEGIN{
    FS = ":"
    numupdates = 0
    interest = 0.0
    months["01"] = "January"
    months["02"] = "February"
    months["03"] = "March"
    months["04"] = "April"
    months["05"] = "May"
    months["06"] = "June"
    months["07"] = "July"
    months["08"] = "August"
    months["09"] = "September"
    months["10"] = "October"
    months["11"] = "November"
    months["12"] = "December"
    prev_bal = 0
    amt = 0
}
{
    Date = $1
    Year = int(getyear(Date))
    Cdt_Amt = $2
    Dbt_Amt = $3
    Bal = $4
    Ttype = $5

    if(Cdt_Amt != ""){
        amt = int(Cdt_Amt)
    }
    else{
        amt = -int(Dbt_Amt)
    }

    if(int(getyear(prev_date)) != 0){
        if(int(getyear(prev_date)) < Year){
            interest = 0
        }
        else{
            num_days = ndays(prev_date, Date)
            interest += 0.05 * num_days / 365 * prev_bal
        }
    }

    if(Bal != ""){
        last_bal = Bal
        output[Date] = $0
    }
    else{
        numupdates += 1
        Bal = prev_bal + amt
        out_date[numupdates] = months[substr(Date, 4, 2)]" "substr(Date, 1, 2)", "substr(Date, 7, 4)
        if(Cdt_Amt != ""){
            out_comment[numupdates] = "Credit of "Cdt_Amt" for "Ttype
        }
        else{
            out_comment[numupdates] = "Debit of "Dbt_Amt" for "Ttype
        }
        out_bal[numupdates] = "Balance = "Bal
        output[Date] = Date":"Cdt_Amt":"Dbt_Amt":"Bal":"Ttype
        if(int(getyear(prev_date)) < Year){
            Bal += round(interest)
            output["31-12-"getyear(prev_date)] = "31-12-"getyear(prev_date)":"round(interest)"::"Bal":INTEREST"
        }
    }

    prev_bal = Bal
    prev_date = Date
}
END{
    if(numupdates == 0){
        printf("+++ No new transactions found\n")
        printf("+++ Interest of this year up to the last transaction = %d\n", round(interest))
    }
    else{
        printf("+++ New transactions found\n")
        printf("Last balance = %d\n", last_bal)
        for(i=1; i<=numupdates; i++){
            printf("%s ", out_date[i])
            printf("%s ", out_comment[i])
            printf("%s\n", out_bal[i])
            
        }
        printf("+++ Interest of this year up to the last transaction = %d\n", round(interest))
    }
}
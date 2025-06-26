DECLARE
    num1 NUMBER := 7;
    num2 NUMBER:= 10;
    num3 NUMBER:= 5;
    max NUMBER
BEGIN
    if num1>num2
    then
        if num1>num3
        THEN
            max := num1
        end if;
        if num3>num1
        then 
            max := num3
        end if;
    end if;
    if num2>num1
    then 
        if num2>num3
        then
            max := num2
        end if;

dbms_output.put_line(max);
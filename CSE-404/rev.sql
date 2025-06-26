DECLARE
    n NUMBER :=9;
BEGIN
   while n>0
   loop
            dbms_output.put_line(n);
            n:=n-2;
    END LOOP;
END;
/

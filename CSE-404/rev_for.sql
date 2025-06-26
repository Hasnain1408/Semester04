DECLARE
    n NUMBER;
BEGIN
    FOR i IN 1..10 LOOP
        IF (mod(i, 2) = 1) THEN
            dbms_output.put_line(10-i);
        END IF;
    END LOOP;
END;
/
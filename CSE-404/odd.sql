DECLARE
    n NUMBER;
BEGIN
    FOR i IN 1..10 LOOP
        IF (mod(i, 2) = 1) THEN
            dbms_output.put_line(i);
        END IF;
    END LOOP;
END;

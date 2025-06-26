DECLARE
    v_input CHAR(1) := '&sv_input';
BEGIN
    IF (v_input>='A' and v_input<='Z')
    THEN
        DBMS_OUTPUT.PUT_LINE('Capital_letter');
    ELSIF (v_input>='a' and v_input<='z')
    THEN
        DBMS_OUTPUT.PUT_LINE('small_letter');
    ELSIF (v_input>='0' and v_input<='9')
    THEN
        DBMS_OUTPUT.PUT_LINE('number');
    ELSE
        DBMS_OUTPUT.PUT_LINE('special_letter');
    END IF;
END;
/

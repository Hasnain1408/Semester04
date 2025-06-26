DECLARE
    vr_emoployee employees%rowtype;
BEGIN
    select * 
    into vr_emoployee
    FROM employees
    WHERE employee_id = &id;
     dbms_output.put_line(vr_emoployee.salary*12);

Exception
    WHEN no_data_found
    THEN
    RAISE_application_error('No data found');
End;
/
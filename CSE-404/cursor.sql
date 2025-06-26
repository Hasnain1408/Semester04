DECLARE
  CURSOR C_ZIP IS
  SELECT
    *
  FROM
    EMPLOYEES;
  VR_ZIP C_ZIP%ROWTYPE;
BEGIN
  OPEN C_ZIP;
  LOOP
    FETCH C_ZIP INTO VR_ZIP;
    if(C_ZIP%FOUND)
    then DBMS_OUTPUT.PUT_LINE(VR_ZIP.SALARY);
    else
    EXIT;
    end if;
    
  END LOOP;
END;
/
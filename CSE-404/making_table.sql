drop TABLE T;
CREATE TABLE hasnain (
    id Number,
    salary Number
);


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
    EXIT when C_ZIP%notfound;
    if(VR_ZIP.salary > 10000)
    then INSERT INTO hasnain VALUES(VR_ZIP.employee_id,VR_ZIP.salary);
    end if;
  END LOOP;
END;
/

SELECT * FROM hasnain;
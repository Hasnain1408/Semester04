CREATE OR REPLACE FUNCTION tax(p_value IN NUMBER, commission_pct IN NUMBER)
    RETURN NUMBER IS
    sal NUMBER;
BEGIN
    sal := (p_value + p_value * NVL(commission_pct, 0)) * 12;
    RETURN (sal * 0.08);
END tax;
/

SELECT employee_id, last_name, salary, tax(salary, commission_pct)
from employees
WHERE department_id = 100;
CREATE or REPLACE FUNCTION get_sal
    (p_id employees.employee_id%TYPE) return NUMBER IS
    v_sal employees.salary%TYPE :=0;
BEGIN 
    select  salary
    into v_sal
    from employees
    where employee_id = p_id;
    return v_sal;
END get_sal;
/


EXECUTE dbms_output.put_line(get_sal(100))
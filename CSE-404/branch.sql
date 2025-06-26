CREATE TABLE branch(
    branch_name VARCHAR(250),
    branch_city VARCHAR(250), 
    assets NUMBER(10),
    PRIMARY KEY (branch_name)
);

INSERT into branch VALUES ('IBBL', 'Uttara', 1000000);
INSERT into branch VALUES ('DBBL', 'Mirpur', 1500000);
INSERT into branch VALUES ('Sonali', 'Motijheel', 900000);
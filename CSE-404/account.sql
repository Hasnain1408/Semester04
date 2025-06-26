CREATE TABLE account(
    account_number NUMBER(10),
    branch_name VARCHAR(250),
    balance NUMBER(10),
    PRIMARY KEY (account_number),
    FOREIGN KEY (branch_name) REFERENCES  branch(branch_name)
);

INSERT into account VALUES (1408, 'IBBL', 10000);
INSERT into account VALUES (1409, 'DBBL', 15000);
INSERT into account VALUES (1410, 'Sonali', 15000);
CREATE TABLE depositor(
    customer_name VARCHAR(250),
    account_number NUMBER(10),
    PRIMARY KEY (customer_name, account_number),
    FOREIGN KEY (customer_name) REFERENCES customer(customer_name),
    FOREIGN KEY (account_number) REFERENCES account(account_number)
);

INSERT into depositor VALUES ('Hasnain', 1408);
INSERT into depositor VALUES ('Sami', 1409);
INSERT into depositor VALUES ('Rifat', 1410);



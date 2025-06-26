CREATE TABLE borrower(
    customer_name VARCHAR(250),
    loan_number VARCHAR(250),
    PRIMARY KEY (customer_name, loan_number),
    FOREIGN KEY (customer_name) REFERENCES customer(customer_name),
    FOREIGN KEY (loan_number) REFERENCES loan(loan_number)
);

INSERT into borrower VALUES ('Sami', 'L-1002');
INSERT into borrower VALUES ('Hasnain', 'L-1001');
INSERT into borrower VALUES ('Rifat', 'L-1003');
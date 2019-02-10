create table publisher(
	Name varchar(15),
	Address varchar(15),
	Phone Number(3),
	Constraint pk_name primary key(Name)
);

create table book(
	Book_id Number(4),
	Title varchar(20),
	Publisher_Name varchar(15),
	Pub_year Number(4),
	Constraint pk_bookid primary key(Book_id),
	Constraint fk_pubname foreign key(Publisher_Name) references publisher(Name) on delete cascade
);

create table book_authors
(
	Book_id Number(4),
	Author_Name varchar(15),
	Constraint fk_bookid foreign key(Book_id) references book(Book_id) on delete cascade 
);

create table library_branch
(
	Branch_id Number(4),
	Branch_Name varchar(10),
	Address varchar(15),
	Constraint pk_branchid primary key(Branch_id)
);

create table book_copies
(
	Book_id number(4),
	Branch_id number(4),
	No_of_copies number(2),
	Constraint fk_branchid foreign key(Branch_id) references library_branch(Branch_id) on delete cascade,
	Constraint fk_bookid1 foreign key(Book_id) references book(Book_id) on delete cascade
);

create table book_lending
(
	Book_id number(4),
	Branch_id number(4),
	Card_No number(2),
	Date_out date,
	Constraint fk_branchid1 foreign key(Branch_id) references library_branch(Branch_id) on delete cascade,
	Constraint fk_bookid2 foreign key(Book_id) references book(Book_id) on delete cascade
);

insert into publisher values ('&Name', '&address', &phone);

insert into book values (&book_id, '&title', '&publisher_name', &pub_year);

insert into book_authors values (&book_id, '&author_name');

insert into book_copies values (&book_id, &branch_id, &No_of_copies);

insert into book_lending values (&book_id, &branch_id, &card_no, '&date_out');

select c.book_id, b.title, b.publisher_name, ba.author_name, c.No_of_copies, l.branch_id
from book b, book_copies c, book_authors ba, library_branch l
where b.book_id = ba.book_id and l.branch_id = c.branch_id and b.book_id = c.book_id
and (c.branch_id, c.book_id) IN (select branch_id, book_id from book_copies group by branch_id, book_id);

select *
from book_lending 
where date_out between '01-jan-17' and '30-jun-17' and card_no IN (select card_no from book_lending group by card_no having COUNT(card_no) > 3);

delete from book where book_id = 5555;

create view publish as
select pub_year from book;
select * from publish;

create view all_copies as
	(select b.title, c.No_of_copies, l.branch_id, l.Branch_Name
	from book b, book_copies c, library_branch l
	where b.book_id = c.book_id and l.branch_id = c.branch_id);
select * from all_copies;
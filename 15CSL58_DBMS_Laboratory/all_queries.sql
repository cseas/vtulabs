select b.title, c.book_id, c.branch_id, l.branch_name
from book b, book_copies c, library_branch l
where b.book_id = c.book_id and c.branch_id=l.branch_id
and (c.book_id, c.branch_id ) in (select c.book_id, c.branch_id from book_copies c group by c.book_id, c.branch_id);

select bl.card_no, b.title
from book_lending bl, book b
where b.book_id=bl.book_id and bl.date_out between '01-jan-17' and '30-jun-17'
and bl.card_no in (select card_no from book_lending group by card_no having count(card_no)>3);

create view books_part as
	select pub_year from book;

create view book_no_copies as
	select b.title, c.no_of_copies
	from book b, book_copies c
	where b.book_id = c.book_id;

select count(customer_id)
from customer 
where grade > (select avg(grade) from customer where city='bangalore');

select s.salesman_id, s.name
from salesman s, customer c
where s.salesman_id = c.salesman_id
group by s.salesman_id, s.name
having count(customer_id)>0;

(select s.name, s.salesman_id, c.customer_name
from salesman s, customer c
where s.salesman_id=c.salesman_id and s.city=c.city)
union
(select s.name, s.salesman_id, 'No Customer'
from salesman s, customer c
where s.salesman_id=c.salesman_id and s.city!=c.city);

create view max_order as
	select s.salesman_id, o.purchase_amt, o.ord_date
	from orders o, salesman s
	where s.salesman_id = o.salesman_id;
select *
from max_order h
where h.purchase_amt in (select max(h1.purchase_amt) from max_ord h1 where h.ord_date=h1.ord_date);

select m.mov_title
from movies m, director d
where d.dir_id=m.dir_id and d.dir_name='hitchcock';

select m.mov_title, a.act_name
from movies m, movie_cast c, actor a
where m.mov_id=c.mov_id and a.act_id=c.act_id
and a.act_id in (select act_id from movie_cast group by act_id having count(mov_id)>1);

(select a.act_name from actor a
join movie_cast m on a.act_id=m.act_id
join movies m1 on m.mov_id=m1.mov_id 
where m1.mov_year < 2000)
intersect
(select a.act_name from actor a
join movie_cast m on a.act_id=m.act_id
join movies m1 on m.mov_id=m1.mov_id 
where m1.mov_year > 2015);

select m.mov_title, max(r.rev_stars)
from movies m, rating r
where m.mov_id=r.mov_id
and r.rev_stars in (select rev_stars from rating where rev_stars>1)
group by m.mov_title
order by m.mov_title;

update rating set rev_stars=5
	where mov_id in (select mov_id from movies where dir_id in (select dir_id from director where dir_name='hitchcock'));

select s.sname, c.ssid
from student s, semsec ss, class c
where s.usn=c.usn and ss.ssid=c.ssid
order by ss.ssid asc;

select ss.sem, ss.sec, s.gender, count(s.gender)
from semsec ss, student s, class c
where ss.ssid=c.ssid and s.usn=c.usn
group by ss.sem, ss.sec, s.gender
order by ss.sem, ss.sec;

create view marks_stud as
	select test1, usn from iamarks where usn='1mv16cs130';
select * from marks_stud;


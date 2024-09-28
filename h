from tabulate import tabulate
import pickle

s = open("books.dat", "wb+")
a = open("teacher.dat", "wb+")
q = open("student.dat", "wb+")


###Functions Needed for update
def updatelibrary():
  n = input('Enter the name of the Book to be Updated')
  nname = input('Enter the new name of the Book')
  ntype = input('Enter the type of the Book')
  nqty = int(input('Enter the number of Books'))
  cur.execute(
    f"'update Books set name='{nname}',type='{ntype}',qty={nqty} where name='{n}';"
  )
  db.commit()

  cur.execute("select * from Books")
  nos = cur.rowcount
  print("number of rows in the table;", nos)
  lst = []
  for j in cur.fetchall():
    lst.append(j)
  print(tabulate(lst, headers=['Name', 'Type', 'Qty'], tablefmt='grid'))

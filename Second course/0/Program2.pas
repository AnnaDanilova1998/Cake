program qq;
 var s,q,a,n,m:integer;
begin
  write('������� ����� ');
  readln(a);
  write('������� ������� ');
  readln(n);
  s:=1;
  q:=0;
  while n<>0 do
   begin
    if odd(n)= true then
     begin
      s:=s*a;
      inc(q);
     end;
    if n shr 1 <>0 then
      begin
       a:=a*a;
       inc(q);
      end;
     n:=n shr 1;
    end;
      writeln('��������� ',s);
      writeln('���������� ��������� ',q);
    end.
      
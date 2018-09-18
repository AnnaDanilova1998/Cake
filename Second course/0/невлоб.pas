program qq;
const
m=10;
 var i,n,p,a,k,rez:integer;
 s:array[1..m] of integer;
 pr:array[0..m] of integer;
begin
  write('¬ведите число ');
  readln(a);
  write('¬ведите степень ');
  readln(n);
  k:=n;
  p:=1;
  for i:=1 to n do
  begin
  s[i]:=p*a;
  p:=p*a;
  end;
  for i:=1 to n do
   write(s[i],' ');
   writeln;
   
  for i:=0 to k do
  begin
   pr[i]:=n mod 2;
   n:=n div 2;
   end;
   for i:= k downto 1 do
   write(pr[i],' ');
   writeln;
   
   rez:=1;
   p:=1;
   for i:= k downto 0 do
    if pr[i]=1 then
     rez:=rez*p*s[i+1];
   writeln('–езультат ',rez);
end. 
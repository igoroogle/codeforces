program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a:array [1..2010] of integer;
   b:array [1..2010] of integer;
   d:array [1..3,1..2010] of integer;
   i,j,n,x,y,tr:integer;
procedure swap(var a,b:integer);
var
   dd:integer;
begin
   dd:=a;
   a:=b;
   b:=dd;
end;
begin
   readln(n);
   read(a[1]);
   b[1]:=1;
   for i:=2 to n do
      begin
         read(x);
         y:=i;
         j:=i-1;
         while (j>0) and (x<a[j]) do
            begin
               a[j+1]:=a[j];
               b[j+1]:=b[j];
               dec(j);
            end;
         a[j+1]:=x;
         b[j+1]:=y;
      end;
   tr:=0;
   d[1,1]:=b[1];
   d[2,1]:=b[1];
   d[3,1]:=b[1];
   for i:=2 to n do
      begin
          d[1,i]:=b[i];
          d[2,i]:=b[i];
          d[3,i]:=b[i];
          if (a[i-1]=a[i]) and (tr<2) then
             begin
                if (tr=0) then swap(d[2,i-1],d[2,i])
                else  swap(d[3,i-1],d[3,i]);
                inc(tr);
             end;

      end;
   if (tr<2) then writeln('NO')
   else
      begin
         writeln('YES');
         for i:=1 to 3 do
            begin
               for j:=1 to n-1 do write(d[i,j],' ');
               writeln(d[i,n]);
            end;
      end;
   readln;
   readln;
end.

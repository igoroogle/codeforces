program ZAD_D;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
   a,b,c,ñ1,d,d1:array [1..1000010] of integer;
   i,j,n:integer;
   s:int64;
procedure quicksort (f,l:integer);
var
   i,j,dd,x:integer;
begin
   randomize;
   x:=random(l-f+1)+f;
   i:=f;
   j:=l;
   repeat
      while (a[i]<a[x]) or ((a[i]=a[x]) and (b[i]<b[x])) do inc(i);
      while (a[j]>a[x]) or ((a[j]=a[x]) and (b[j]>b[x])) do dec(j);
      if (i<=j) then
        begin
           dd:=a[i];
           a[i]:=a[j];
           a[j]:=dd;
           dd:=b[i];
           b[i]:=b[j];
           b[j]:=dd;
           inc(i);
           dec(j);
        end;
   until i>j;
   if (i<l) then quicksort(i,l);
   if (f<j) then quicksort(f,j);
end;
procedure quicksort2 (f,l:integer);
var
   i,j,dd,x:integer;
begin
   randomize;
   x:=random(l-f+1)+f;
   i:=f;
   j:=l;
   repeat
      while (c[i]<c[x]) or ((c[i]=c[x]) and (c1[i]<c1[x])) do inc(i);
      while (c[j]>c[x]) or ((c[j]=c[x]) and (c1[j]>c1[x])) do dec(j);
      if (i<=j) then
        begin
           dd:=c[i];
           c[i]:=c[j];
           c[j]:=dd;
           dd:=c1[i];
           c1[i]:=c1[j];
           c1[j]:=dd;
           inc(i);
           dec(j);
        end;
   until i>j;
   if (i<l) then quicksort2(i,l);
   if (f<j) then quicksort2(f,j);
end;
procedure quicksort3 (f,l:integer);
var
   i,j,dd,x:integer;
begin
   randomize;
   x:=random(l-f+1)+f;
   i:=f;
   j:=l;
   repeat
      while (d[i]<d[x]) or ((d[i]=d[x]) and (d1[i]<d1[x])) do inc(i);
      while (d[j]>d[x]) or ((d[j]=d[x]) and (d1[j]>d1[x])) do dec(j);
      if (i<=j) then
        begin
           dd:=d[i];
           d[i]:=d[j];
           d[j]:=dd;
           dd:=d1[i];
           d1[i]:=d1[j];
           d1[j]:=dd;
           inc(i);
           dec(j);
        end;
   until i>j;
   if (i<l) then quicksort3(i,l);
   if (f<j) then quicksort3(f,j);
end;
begin
   readln(n);
   for i:=1 to n do
      begin
         read(a[i]);
         b[i]:=i;
      end;
   readln;
   quicksort(1,n);
   for i:=1 to n do c[i]:=1;
   for i:=2 to n do
      if (a[i-1]=a[i]) then c[b[i]]:=c[b[i-1]]+1;
   for i:=1 to n do d[i]:=1;
   for i:=n-1 downto 1 do
      if (a[i+1]=a[i]) then d[b[i]]:=d[b[i+1]]+1;
   quicksort2(1,n);
   quicksort3(1,n);
   s:=0;
   j:=1;
   for i:=1 to n do
      begin
        while (j<=n) and (d[j]<c[i]) do inc(j);
        s:=s+j-1;
      end;
   writeln(s);
   readln;
end.

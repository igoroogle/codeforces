program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
   n,i,j,s:integer;
   a:array [1..65] of integer;
   d,d1,d2:array [0..1000000] of integer;
procedure rec(k:integer);
begin
   if (k=0) then exit;
   rec(d2[k]);
   if (k=n) then writeln(d1[k])
   else write(d1[k],' ');
end;
begin
   readln(n);
   s := 0;
   for i:=1 to n do
      begin
         j:=i;
         while (j>0) do
            begin
               if (j mod 10 <> 0) and (j mod 10 <>1) then break;
               j:=j div 10;
            end;
         if (j = 0) then
            begin
               inc(s);
               a[s]:=i;
            end;
      end;
   d[0] := 0;
   for i:=1 to n do
      begin
         d[i]:=maxint;
         for j:=1 to s do
            if (i-a[j]>=0) and (d[i-a[j]]+1<d[i]) then
               begin
                  d[i]:=d[i-a[j]]+1;
                  d1[i]:=a[j];
                  d2[i]:=i-a[j];
               end;
      end;
   writeln(d[n]);
   rec(n);
   readln;
end.

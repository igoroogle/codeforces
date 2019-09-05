program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a,b:array [0..200010] of int64;
   n,i:integer;
   s,k:int64;
function srv():boolean;
var
   i,m,k:integer;
begin
   k:=0;
   if (a[0]<b[0]) then m:=a[0]
   else m:=b[0];
   for i:=1 to m do
      if (a[i]<>b[i]) then
         begin
            if (a[i]>b[i]) then k:=1
            else k:=2;
            break;
         end;
   if (k=0) and (a[i]>b[i]) then k:=1
   else if (k=0) and (a[i]>b[i]) then k:=2;
   if (k<2) then srv:=true
   else srv:=false;
end;
begin
   readln(n);
   a[0]:=0;
   b[0]:=0;
   s:=0;
   for i:=1 to n do
      begin
         read(k);
         s:=s+k;
         if (k>0) then
            begin
               inc(a[0]);
               a[a[0]]:=k;
            end
         else if (k<0) then
            begin
               inc(b[0]);
               b[b[0]]:=-k;
            end;
      end;
   if (s>0) or ((s=0) and (srv())) then writeln('first')
   else writeln('second');
   readln;
   readln;
end.

program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   a:array [1..1010,1..2] of string;
   q,i,j,n,pr:integer;
   s,s1,s2:string;
   f,f1:boolean;
begin
   readln(q);
   n:=0;
   for i:=1 to q do
      begin
         readln(s);
         pr:=pos(' ',s);
         s1:=copy(s,1,pr-1);
         s2:=copy(s,pr+1,length(s)-pr);
         f:=true;
         f1:=true;
         for j:=1 to n do
            if (s2=a[j,2]) then
               begin
                  f1:=false;
                  break;
               end;
         if (f1) then
            begin
               for j:=1 to n do
                  if (s1=a[j,2]) then
                     begin
                        a[j,2]:=s2;
                        f:=false;
                        break;
                     end
            end;
         if (f) and (f1) then
            begin
               inc(n);
               a[n,1]:=s1;
               a[n,2]:=s2;
            end;
      end;
   writeln(n);
   for i:=1 to n do writeln(a[i,1],' ',a[i,2]);
   readln;
end.

program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   l,r,i,j,k:int64;
function nod(a,b:int64):int64;
begin
   if (b=0) then nod:=a
   else nod:=nod(b,a mod b);
end;
begin
   readln(l,r);
   i:=l;
   while i<=r do
      begin
         j:=i+1;
         while j<=r do
            begin
               k:=j+1;
               while k<=r do
                  begin
                     if (nod(i,j)=1) and (nod(j,k)=1) and (nod(i,k)<>1) then
                        begin
                           writeln(i,' ',j,' ',k);
                           readln;
                           halt;
                        end;
                     inc(k);
                  end;
               inc(j);
            end;
         inc(i);
      end;
   writeln(-1);
   readln;
end.

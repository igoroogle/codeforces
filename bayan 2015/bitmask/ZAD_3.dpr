program ZAD_3;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const
   dl = 100000;
var
   a,b:array [1..dl] of integer;
   n,i,j,l,r,k,p:integer;
begin
   readln(n,k);
   for i:=1 to dl do b[i]:=0;
   p:=0;
   for i:=1 to n do
      begin
         read(a[i]);
         inc(b[a[i]]);
         if (b[a[i]]=1) then inc(p);
      end;
   readln;
   i:=1;
   j:=n;
   l:=-1;
   r:=-1;
   while (p>k) do
      begin
         dec(b[a[i]]);
         if (b[a[i]]=0) then dec(p);
         inc(i);
      end;
   while p=k do
      begin
         l:=i;
         r:=j;
         if (b[a[i]]>1) then
            begin
               dec(b[a[i]]);
               inc(i)
            end
         else
            begin
               dec(b[a[j]]);
               if (b[a[j]]=0) then dec(p);
               dec(j);
            end
      end;
   writeln(l,' ',r);
   readln;
end.

program ZAD_B_2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   i,j,n,a1,b1,k,l,r:integer;
   a,b,c:array [1..110] of integer;
begin
   readln(n);
   k:=(n+1) div 2;
   writeln('Q ',1,' ',k);
   flush(output);
   a1:=1;
   b1:=k;
   for i:=1 to k do
      begin
         read(a[i]);
         while (a1<a[i]) do
            begin
               inc(b1);
               a[b1]:=a1;
               inc(a1);
            end;
         inc(a1);
      end;
   readln;
   while a1<=n do
      begin
         inc(b1);
         a[b1]:=a1;
         inc(a1);
      end;
   a1:=1;
   b1:=n;
   while a1+1<b1 do
      begin
         dec(b1);
         inc(a1);
         writeln('Q ',a1,' ',b1);
         flush(output);
         for i:=a1 to b1 do read(b[i]);
         readln;
         l:=a1-1;
         r:=k;
         for i:=a1 to b1 do
            begin
               for j:=a1-1 to b1+1 do
                  if (a[j]=b[i]) then
                     begin
                        if (j>k) then
                           begin
                              inc(r);
                              c[r]:=a[j];
                           end
                        else
                           begin
                              inc(l);
                              c[l]:=a[j];
                           end
                     end;
            end;
         for i:=a1-1 to k do
            begin
               for j:=a1 to k do
                  begin
                     if (c[j]=a[i]) then break;
                     if (j=k) then a[a1-1]:=a[i];
                  end;
            end;
         for i:=k+1 to b1+1 do
            begin
               for j:=k+1 to b1 do
                  begin
                     if (c[j]=a[i]) then break;
                     if (j=b1) then a[b1+1]:=a[i];
                  end;
            end;
         for i:=a1 to b1 do a[i]:=c[i];
      end;
   write('A ');
   for i:=1 to n-1 do write(a[i],' ');
   writeln(a[n]);
   flush(output);
   readln;
end.

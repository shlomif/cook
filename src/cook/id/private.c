/*
 *      cook - file construction tool
 *      Copyright (C) 1997, 2006-2009 Peter Miller
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 3 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program. If not, see
 *      <http://www.gnu.org/licenses/>.
 */

#include <cook/id/private.h>
#include <common/mem.h>
#include <common/trace.h>


id_ty *
id_instance_new(id_method_ty *mp)
{
    id_ty           *idp;

    trace(("id_new()\n{\n"));
    assert(mp);
    trace(("is a %s\n", mp->name));
    idp = mem_alloc(mp->size);
    idp->method = mp;
    trace(("return %p;\n", idp));
    trace(("}\n"));
    return idp;
}


void
id_instance_delete(id_ty *idp)
{
    assert(idp);
    assert(idp->method);
    assert(idp->method->destructor);
    idp->method->destructor(idp);
    idp->method = 0; /* paranoia */
    mem_free(idp);
}

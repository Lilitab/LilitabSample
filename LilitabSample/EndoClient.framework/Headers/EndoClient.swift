//
//  EndoClient.swift
//  EndoClient
//
//  Created by Kevin Snow on 2/19/16.
//  Copyright © 2016 MynaBay. All rights reserved.
//

import Foundation
import EndoClient

public func EndoLog(format: String, _ args: CVarArgType...) -> ()
{
    EndoLogVA(format,getVaList(args))
}

public func EndoLogWithCategory(category: String, _ format: String, _ args: CVarArgType...) -> ()
{
    EndoLogWithCategoryVA(category,format,getVaList(args))
}

public func EndoLogStackTrace(format: String, _ args: CVarArgType...) -> ()
{
    EndoLogStackTraceVA(format,getVaList(args))
}

public func EndoLogWithCategoryStackTrace(category: String, _ format: String, _ args: CVarArgType...) -> ()
{
    EndoLogWithCategoryStackTraceVA(category,format,getVaList(args))
}

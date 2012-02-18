/*******************************************************************************
 * Copyright (c) 2012, Jean-David Gadina <macmade@eosgarden.com>
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/* $Id$ */

/*!
 * @header          ...
 * @author          Jean-David Gadina <macmade@eosgarden>
 * @copyright       (c) 2012, eosgarden
 * @abstract        ...
 */

#import <Foundation/Foundation.h>

typedef enum
{
    EOSFileTypeUnknown             = 0x00,
    EOSFileTypeDirectory           = 0x01,
    EOSFileTypeRegularFile         = 0x02,
    EOSFileTypeSymbolicLink        = 0x03,
    EOSFileTypeSocket              = 0x04,
    EOSFileTypeCharacterSpecial    = 0x05,
    EOSFileTypeBlockSpecial        = 0x06
}
EOSFileType;

typedef enum
{
    EOSFileFlagsArchived           = 0x01,
    EOSFileFlagsHidden             = 0x02,
    EOSFileFlagsNoDump             = 0x04,
    EOSFileFlagsOpaque             = 0x08,
    EOSFileFlagsSystemAppendOnly   = 0x10,
    EOSFileFlagsSystemImmutable    = 0x20,
    EOSFileFlagsUserAppendOnly     = 0x40,
    EOSFileFlagsUserImmutable      = 0x80
}
EOSFileFlags;

@interface EOSFile: NSObject
{
@protected
    
    NSURL                 * _url;
    NSString              * _path;
    EOSFileType             _type;
    EOSFileFlags            _flags;
    BOOL                    _immutable;
    BOOL                    _appendOnly;
    BOOL                    _busy;
    BOOL                    _readable;
    BOOL                    _writeable;
    BOOL                    _executable;
    BOOL                    _extensionHidden;
    NSUInteger              _referenceCount;
    NSUInteger              _systemNumber;
    NSUInteger              _systemFileNumber;
    NSUInteger              _deviceIdentifier;
    NSUInteger              _HFSCreatorCode;
    NSUInteger              _HFSTypeCode;
    NSUInteger              _bytes;
    CGFloat                 _kiloBytes;
    CGFloat                 _megaBytes;
    CGFloat                 _gigaBytes;
    CGFloat                 _teraBytes;
    NSString              * _humanReadableSize;
    NSUInteger              _ownerID;
    NSUInteger              _groupID;
    NSString              * _owner;
    NSString              * _group;
    NSUInteger              _permissions;
    NSUInteger              _octalPermissions;
    NSString              * _humanReadablePermissions;
    NSString              * _name;
    NSString              * _displayName;
    NSString              * _extension;
    NSDate                * _creationDate;
    NSDate                * _modificationDate;
    
@private
    
    id _EOSFile_Reserved[ 5 ] __attribute__( ( unused ) );
}

@property( atomic, readonly ) NSURL               * url;
@property( atomic, readonly ) NSString            * path;
@property( atomic, readonly ) EOSFileType           type;
@property( atomic, readonly ) EOSFileFlags          flags;
@property( atomic, readonly ) BOOL                  immutable;
@property( atomic, readonly ) BOOL                  appendOnly;
@property( atomic, readonly ) BOOL                  busy;
@property( atomic, readonly ) BOOL                  readable;
@property( atomic, readonly ) BOOL                  writeable;
@property( atomic, readonly ) BOOL                  executable;
@property( atomic, readonly ) BOOL                  extensionHidden;
@property( atomic, readonly ) NSUInteger            referenceCount;
@property( atomic, readonly ) NSUInteger            systemNumber;
@property( atomic, readonly ) NSUInteger            systemFileNumber;
@property( atomic, readonly ) NSUInteger            HFSCreatorCode;
@property( atomic, readonly ) NSUInteger            HFSTypeCode;
@property( atomic, readonly ) NSUInteger            bytes;
@property( atomic, readonly ) CGFloat               kiloBytes;
@property( atomic, readonly ) CGFloat               megaBytes;
@property( atomic, readonly ) CGFloat               gigaBytes;
@property( atomic, readonly ) CGFloat               teraBytes;
@property( atomic, readonly ) NSString            * humanReadableSize;
@property( atomic, readonly ) NSUInteger            deviceIdentifier;
@property( atomic, readonly ) NSUInteger            ownerID;
@property( atomic, readonly ) NSUInteger            groupID;
@property( atomic, readonly ) NSString            * owner;
@property( atomic, readonly ) NSString            * group;
@property( atomic, readonly ) NSUInteger            permissions;
@property( atomic, readonly ) NSUInteger            octalPermissions;
@property( atomic, readonly ) NSString            * humanReadablePermissions;
@property( atomic, readonly ) NSString            * name;
@property( atomic, readonly ) NSString            * displayName;
@property( atomic, readonly ) NSString            * extension;
@property( atomic, readonly ) NSDate              * creationDate;
@property( atomic, readonly ) NSDate              * modificationDate;
@property( atomic, readonly ) NSData              * data;

+ ( EOSFile * )fileWithPath: ( NSString * )path;
+ ( EOSFile * )fileWithURL: ( NSURL * )url;
+ ( EOSFile * )newFileWithPath: ( NSString * )path data: ( NSData * )data;
+ ( EOSFile * )newFileWithURL: ( NSURL * )url data: ( NSData * )data;
- ( id )initWithPath: ( NSString * )path;
- ( id )initWithURL: ( NSURL * )url;
- ( NSFileHandle * )fileHandleForReading;
- ( NSFileHandle * )fileHandleForWriting;
- ( NSFileHandle * )fileHandleForUpdating;
- ( NSString * )creationDateWithFormat: ( NSString * )format;
- ( NSString * )modificationDateWithFormat: ( NSString * )format;
- ( BOOL )writeData: ( NSData * )data;
- ( void )delete: ( NSError ** )error;

@end

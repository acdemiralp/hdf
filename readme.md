### HDF
Header-only C++20 wrapper for HDF5.

### Usage Notes
- Define `HDF_USE_EXCEPTIONS` to check the return values of all viable functions against `0` and throw an exception otherwise.
- Define `HDF_USE_LATEST` to enable latest futures (e.g. event sets).

### Design notes.
- Deprecated functions are omitted (the library is bloated enough with its ~740 non-deprecated functions).

### Coverage ([Reference](https://portal.hdfgroup.org/display/HDF5/Libraries+and+Tools+Reference))
- [ ] Core
  - [ ] Attributes
    - [ ] H5A_CLOSE  
    - [ ] H5A_CREATE2
    - [ ] H5A_CREATE_BY_NAME 
    - [ ] H5A_DELETE 
    - [ ] H5A_DELETE_BY_IDX 
    - [ ] H5A_DELETE_BY_NAME 
    - [ ] H5A_EXISTS 
    - [ ] H5A_EXISTS_BY_NAME 
    - [ ] H5A_GET_CREATE_PLIST 
    - [ ] H5A_GET_INFO  
    - [ ] H5A_GET_INFO_BY_IDX  
    - [ ] H5A_GET_INFO_BY_NAME  
    - [ ] H5A_GET_NAME  
    - [ ] H5A_GET_NAME_BY_IDX  
    - [ ] H5A_GET_SPACE  
    - [ ] H5A_GET_STORAGE_SIZE  
    - [ ] H5A_GET_TYPE 
    - [ ] H5A_ITERATE2
    - [ ] H5A_ITERATE_BY_NAME  
    - [ ] H5A_OPEN  
    - [ ] H5A_OPEN_BY_IDX  
    - [ ] H5A_OPEN_BY_NAME  
    - [ ] H5A_READ  
    - [ ] H5A_RENAME  
    - [ ] H5A_RENAME_BY_NAME  
    - [ ] H5A_WRITE
  - [ ] Data Sets
    - [ ] H5D_CLOSE
    - [ ] H5D_CREATE2  
    - [ ] H5D_CREATE_ANON  
    - [ ] H5D_FILL  
    - [ ] H5D_FLUSH  
    - [ ] H5D_GATHER  
    - [ ] H5D_GET_ACCESS_PLIST  
    - [ ] H5D_GET_CHUNK_INFO 
    - [ ] H5D_GET_CHUNK_INFO_BY_COORD 
    - [ ] H5D_GET_CHUNK_STORAGE_SIZE  
    - [ ] H5D_GET_CREATE_PLIST  
    - [ ] H5D_GET_NUM_CHUNKS  
    - [ ] H5D_GET_OFFSET 
    - [ ] H5D_GET_SPACE 
    - [ ] H5D_GET_SPACE_STATUS  
    - [ ] H5D_GET_STORAGE_SIZE  
    - [ ] H5D_GET_TYPE  
    - [ ] H5D_ITERATE 
    - [ ] H5D_OPEN2
    - [ ] H5D_READ  
    - [ ] H5D_READ_CHUNK  
    - [ ] H5D_REFRESH  
    - [ ] H5D_SCATTER  
    - [ ] H5D_SET_EXTENT  
    - [ ] H5D_VLEN_GET_BUF_SIZE  
    - [ ] H5D_WRITE  
    - [ ] H5D_WRITE_CHUNK 
  - [ ] Data Spaces
    - [ ] H5S_CLOSE
    - [ ] H5S_COMBINE_HYPERSLAB
    - [ ] H5S_COMBINE_SELECT
    - [ ] H5S_COPY  
    - [ ] H5S_CREATE  
    - [ ] H5S_CREATE_SIMPLE  
    - [ ] H5S_DECODE  
    - [ ] H5S_ENCODE2
    - [ ] H5S_EXTENT_COPY  
    - [ ] H5S_EXTENT_EQUAL  
    - [ ] H5S_GET_REGULAR_HYPERSLAB  
    - [ ] H5S_GET_SELECT_BOUNDS  
    - [ ] H5S_GET_SELECT_ELEM_NPOINTS  
    - [ ] H5S_GET_SELECT_ELEM_POINTLIST  
    - [ ] H5S_GET_SELECT_HYPER_BLOCKLIST  
    - [ ] H5S_GET_SELECT_HYPER_NBLOCKS     
    - [ ] H5S_GET_SELECT_NPOINTS
    - [ ] H5S_GET_SELECT_TYPE  
    - [ ] H5S_GET_SIMPLE_EXTENT_DIMS 
  - [ ] Data Types
    - [x] H5T_CLOSE
    - [ ] H5T_COMMIT2
    - [ ] H5T_COMMIT_ANON
    - [x] H5T_COMMITTED
    - [x] H5T_COPY
    - [ ] H5T_CREATE
    - [ ] H5T_DETECT_CLASS
    - [x] H5T_EQUAL
    - [x] H5T_FLUSH
    - [ ] H5T_GET_CLASS
    - [ ] H5T_GET_CREATE_PLIST
    - [ ] H5T_GET_NATIVE_TYPE
    - [ ] H5T_GET_SIZE
    - [ ] H5T_GET_SUPER
    - [x] H5T_LOCK
    - [ ] H5T_OPEN2
    - [x] H5T_REFRESH
    - [ ] H5T_SET_SIZE
    - [ ] H5T_COMPILER_CONV
    - [ ] H5T_CONVERT
    - [ ] H5T_DECODE
    - [ ] H5T_ENCODE
    - [ ] H5T_FIND
    - [x] H5T_REGISTER
    - [x] H5T_UNREGISTER
    - [ ] H5T_GET_CSET
    - [ ] H5T_GET_EBIAS
    - [ ] H5T_GET_FIELDS
    - [ ] H5T_GET_INPAD
    - [ ] H5T_GET_NORM
    - [ ] H5T_GET_OFFSET
    - [ ] H5T_GET_ORDER
    - [ ] H5T_GET_PAD
    - [ ] H5T_GET_PRECISION
    - [ ] H5T_GET_SIGN
    - [ ] H5T_GET_STRPAD
    - [ ] H5T_IS_VARIABLE_STR
    - [ ] H5T_SET_CSET
    - [ ] H5T_SET_EBIAS
    - [ ] H5T_SET_FIELDS
    - [ ] H5T_SET_INPAD
    - [ ] H5T_SET_NORM
    - [ ] H5T_SET_OFFSET
    - [ ] H5T_SET_ORDER
    - [ ] H5T_SET_PAD
    - [ ] H5T_SET_PRECISION
    - [ ] H5T_SET_SIGN
    - [ ] H5T_SET_STRPAD
    - [ ] H5T_ARRAY_CREATE2
    - [ ] H5T_GET_ARRAY_DIMS2
    - [ ] H5T_GET_ARRAY_NDIMS
    - [ ] H5T_GET_MEMBER_CLASS
    - [ ] H5T_GET_MEMBER_INDEX
    - [ ] H5T_GET_MEMBER_NAME
    - [ ] H5T_GET_MEMBER_OFFSET
    - [ ] H5T_GET_MEMBER_TYPE
    - [ ] H5T_GET_NMEMBERS
    - [ ] H5T_INSERT
    - [ ] H5T_PACK
    - [ ] H5T_VLEN_CREATE
    - [ ] H5T_GET_TAG
    - [ ] H5T_SET_TAG
    - [ ] H5T_ENUM_CREATE
    - [ ] H5T_ENUM_INSERT
    - [ ] H5T_ENUM_NAMEOF
    - [ ] H5T_ENUM_VALUEOF
    - [ ] H5T_GET_MEMBER_INDEX
    - [ ] H5T_GET_MEMBER_NAME
    - [ ] H5T_GET_MEMBER_VALUE
    - [ ] H5T_GET_NMEMBERS
  - [ ] Error Handling
    - [ ] H5E_AUTO_IS_V2
    - [ ] H5E_CLEAR2
    - [ ] H5E_CLOSE_MSG
    - [ ] H5E_CLOSE_STACK
    - [ ] H5E_CREATE_MSG
    - [ ] H5E_CREATE_STACK
    - [ ] H5E_GET_AUTO2
    - [ ] H5E_GET_CLASS_NAME
    - [ ] H5E_GET_CURRENT_STACK
    - [ ] H5E_GET_MSG 
    - [ ] H5E_GET_NUM
    - [ ] H5E_POP
    - [ ] H5E_PRINT2
    - [ ] H5E_PUSH2
    - [ ] H5E_REGISTER_CLASS
    - [ ] H5E_SET_AUTO2
    - [ ] H5E_SET_CURRENT_STACK
    - [ ] H5E_UNREGISTER_CLASS
    - [ ] H5E_WALK2
  - [x] Event Set
    - [x] H5ES_CLOSE  
    - [x] H5ES_CREATE
    - [x] H5ES_GET_COUNT
    - [x] H5ES_GET_ERR_STATUS
    - [x] H5ES_GET_ERR_COUNT
    - [x] H5ES_GET_ERR_INFO
    - [x] H5ES_GET_OP_COUNTER
    - [x] H5ES_WAIT
  - [ ] Files
    - [ ] H5F_CLEAR_ELINK_FILE_CACHE 
    - [ ] H5F_CLOSE 
    - [ ] H5F_CREATE 
    - [ ] H5F_DELETE 
    - [ ] H5F_FLUSH 
    - [ ] H5F_GET_ACCESS_PLIST 
    - [ ] H5F_GET_CREATE_PLIST 
    - [ ] H5F_GET_DSET_NO_ATTRS_HINT 
    - [ ] H5F_GET_EOA 
    - [ ] H5F_GET_FILE_IMAGE 
    - [ ] H5F_GET_FILENO 
    - [ ] H5F_GET_FILESIZE 
    - [ ] H5F_GET_FREE_SECTIONS 
    - [ ] H5F_GET_FREESPACE 
    - [ ] H5F_GET_INFO2 
    - [ ] H5F_GET_INTENT  
    - [ ] H5F_GET_MDC_CONFIG  
    - [ ] H5F_GET_MDC_HIT_RATE 
    - [ ] H5F_GET_MDC_IMAGE_INFO 
    - [ ] H5F_GET_MDC_LOGGING_STATUS 
    - [ ] H5F_GET_MDC_SIZE 
    - [ ] H5F_GET_METADATA_READ_RETRY_INFO 
    - [ ] H5F_GET_MPI_ATOMICITY  
    - [ ] H5F_GET_NAME 
    - [ ] H5F_GET_OBJ_COUNT 
    - [ ] H5F_GET_OBJ_IDS 
    - [ ] H5F_GET_PAGE_BUFFERING_STATS 
    - [ ] H5F_GET_VFD_HANDLE 
    - [ ] H5F_INCREMENT_FILESIZE 
    - [ ] H5F_IS_ACCESSIBLE
    - [ ] H5F_IS_HDF5 
    - [ ] H5F_MOUNT 
    - [ ] H5F_OPEN 
    - [ ] H5F_REOPEN 
    - [ ] H5F_RESET_MDC_HIT_RATE_STATS 
    - [ ] H5F_RESET_PAGE_BUFFERING_STATS 
    - [ ] H5F_SET_DSET_NO_ATTRS_HINT 
    - [ ] H5F_SET_LATEST_FORMAT 
    - [ ] H5F_SET_LIBVER_BOUNDS 
    - [ ] H5F_SET_MDC_CONFIG 
    - [ ] H5F_SET_MPI_ATOMICITY 
    - [ ] H5F_START_SWMR_WRITE 
    - [ ] H5F_START_MDC_LOGGING 
    - [ ] H5F_STOP_MDC_LOGGING 
    - [ ] H5F_UNMOUNT
  - [x] Filters
    - [x] H5Z_FILTER_AVAIL 
    - [x] H5Z_GET_FILTER_INFO
    - [x] H5Z_REGISTER
    - [x] H5Z_UNREGISTER
  - [ ] Groups
    - [x] H5G_CLOSE 
    - [*] H5G_CREATE2
    - [*] H5G_CREATE_ANON
    - [x] H5G_FLUSH   
    - [*] H5G_GET_CREATE_PLIST 
    - [x] H5G_GET_INFO 
    - [*] H5G_GET_INFO_BY_IDX 
    - [*] H5G_GET_INFO_BY_NAME 
    - [*] H5G_OPEN2
    - [x] H5G_REFRESH 
  - [ ] Identifiers
    - [ ] H5I_CLEAR_TYPE
    - [ ] H5I_DEC_REF
    - [ ] H5I_DEC_TYPE_REF
    - [ ] H5I_DESTROY_TYPE
    - [ ] H5I_GET_FILE_ID
    - [ ] H5I_GET_NAME
    - [ ] H5I_GET_REF
    - [ ] H5I_GET_TYPE
    - [ ] H5I_GET_TYPE_REF
    - [ ] H5I_INC_REF
    - [ ] H5I_INC_TYPE_REF
    - [ ] H5I_IS_VALID
    - [ ] H5I_ITERATE
    - [ ] H5I_NMEMBERS
    - [ ] H5I_OBJECT_VERIFY
    - [ ] H5I_REGISTER
    - [ ] H5I_REGISTER_TYPE
    - [ ] H5I_REMOVE_VERIFY
    - [ ] H5I_SEARCH
    - [ ] H5I_TYPE_EXISTS
  - [x] Library
    - [x] H5_ALLOCATE_MEMORY
    - [x] H5_CHECK_VERSION
    - [x] H5_CLOSE
    - [x] H5_DONT_ATEXIT
    - [x] H5_FREE_MEMORY
    - [x] H5_GARBAGE_COLLECT
    - [x] H5_GET_ALLOC_STATS
    - [x] H5_GET_FREE_LIST_SIZES
    - [x] H5_GET_LIBVERSION
    - [x] H5_IS_LIBRARY_THREADSAFE
    - [x] H5_OPEN
    - [x] H5_RESIZE_MEMORY
    - [x] H5_SET_FREE_LIST_LIMITS
    - [x] H5_VERSION_GE
    - [x] H5_VERSION_LE
  - [ ] Links
    - [ ] H5L_COPY
    - [ ] H5L_CREATE_EXTERNAL
    - [ ] H5L_CREATE_HARD
    - [ ] H5L_CREATE_SOFT
    - [ ] H5L_CREATE_UD
    - [ ] H5L_DELETE
    - [ ] H5L_DELETE_BY_IDX
    - [ ] H5L_EXISTS
    - [ ] H5L_GET_INFO
    - [ ] H5L_GET_INFO_BY_IDX
    - [ ] H5L_GET_NAME_BY_IDX
    - [ ] H5L_GET_VAL
    - [ ] H5L_GET_VAL_BY_IDX
    - [ ] H5L_IS_REGISTERED
    - [ ] H5L_ITERATE
    - [ ] H5L_ITERATE_BY_NAME
    - [ ] H5L_MOVE
    - [ ] H5L_REGISTER
    - [ ] H5L_UNPACK_ELINK_VAL
    - [ ] H5L_UNREGISTER
    - [ ] H5L_VISIT
    - [ ] H5L_VISIT_BY_NAME
  - [ ] Map
    - [x] H5M_CLOSE    
    - [x] H5M_CREATE
    - [x] H5M_CREATE_ANON
    - [ ] H5M_DELETE
    - [ ] H5M_GET
    - [x] H5M_GET_ACCESS_PLIST
    - [ ] H5M_GET_COUNT
    - [x] H5M_GET_CREATE_PLIST    
    - [x] H5M_GET_KEY_TYPE
    - [x] H5M_GET_VAL_TYPE    
    - [ ] H5M_EXISTS
    - [ ] H5M_ITERATE
    - [ ] H5M_ITERATE_BY_NAME
    - [x] H5M_OPEN
    - [ ] H5M_PUT
  - [ ] Objects
    - [ ] H5O_ARE_MDC_FLUSHES_DISABLED
    - [ ] H5O_CLOSE
    - [ ] H5O_COPY
    - [ ] H5O_DECR_REFCOUNT
    - [ ] H5O_DISABLE_MDC_FLUSHES
    - [ ] H5O_ENABLE_MDC_FLUSHES
    - [ ] H5O_EXISTS_BY_NAME
    - [ ] H5O_FLUSH
    - [ ] H5O_GET_COMMENT
    - [ ] H5O_GET_COMMENT_BY_NAME 
    - [ ] H5O_GET_INFO2
    - [ ] H5O_GET_INFO_BY_IDX2 
    - [ ] H5O_GET_INFO_BY_NAME2  
    - [ ] H5O_INCR_REFCOUNT
    - [ ] H5O_LINK  
    - [ ] H5O_OPEN  
    - [ ] H5O_OPEN_BY_ADDR
    - [ ] H5O_OPEN_BY_IDX
    - [ ] H5O_REFRESH
    - [ ] H5O_VISIT2
    - [ ] H5O_VISIT_BY_NAME2
  - [x] Plugins
    - [x] H5PL_APPEND
    - [x] H5PL_GET
    - [x] H5PL_GET_LOADING_STATE
    - [x] H5PL_INSERT
    - [x] H5PL_PREPEND
    - [x] H5PL_REMOVE
    - [x] H5PL_REPLACE
    - [x] H5PL_SET_LOADING_STATE
    - [x] H5PL_SIZE
  - [ ] Property Lists
    - [x] General
      - [x] H5P_CLOSE
      - [x] H5P_COPY
      - [x] H5P_CREATE
      - [x] H5P_DECODE
      - [x] H5P_ENCODE
      - [x] H5P_GET_CLASS
    - [ ] File Creation
      - [ ] H5P_GET_FILE_SPACE_PAGE_SIZE
      - [ ] H5P_GET_FILE_SPACE_STRATEGY
      - [ ] H5P_GET_ISTORE_K
      - [ ] H5P_GET_SHARED_MESG_INDEX
      - [ ] H5P_GET_SHARED_MESG_NINDEXES
      - [ ] H5P_GET_SHARED_MESG_PHASE_CHANGE
      - [ ] H5P_GET_SIZES
      - [ ] H5P_GET_SYM_K
      - [ ] H5P_GET_USERBLOCK
      - [ ] H5P_SET_FILE_SPACE_PAGE_SIZE
      - [ ] H5P_SET_FILE_SPACE_STRATEGY
      - [ ] H5P_SET_ISTORE_K
      - [ ] H5P_SET_SHARED_MESG_INDEX
      - [ ] H5P_SET_SHARED_MESG_NINDEXES
      - [ ] H5P_SET_SHARED_MESG_PHASE_CHANGE
      - [ ] H5P_SET_SIZES
      - [ ] H5P_SET_SYM_K
      - [ ] H5P_SET_USERBLOCK
    - [ ] File Access
      - [ ] H5P_GET_ALIGNMENT
      - [ ] HP5_GET_CACHE
      - [ ] H5P_GET_COLL_METADATA_WRITE
      - [ ] H5P_GET_CORE_WRITE_TRACKING
      - [ ] H5P_GET_DRIVER
      - [ ] H5P_GET_DRIVER_INFO
      - [ ] H5P_GET_ELINK_FILE_CACHE_SIZE
      - [ ] H5P_GET_EVICT_ON_CLOSE
      - [ ] H5P_GET_FAMILY_OFFSET
      - [ ] H5P_GET_FAPL_CORE
      - [ ] H5P_GET_FAPL_DIRECT
      - [ ] H5P_GET_FAPL_FAMILY
      - [ ] H5P_GET_FAPL_HDFS
      - [ ] H5P_GET_FAPL_MPIO
      - [ ] H5P_GET_FAPL_MULTI
      - [ ] H5P_GET_FAPL_ROS3
      - [ ] H5P_GET_FAPL_SPLITTER
      - [ ] H5P_GET_FCLOSE_DEGREE
      - [ ] H5P_GET_FILE_IMAGE
      - [ ] H5P_GET_FILE_IMAGE_CALLBACKS
      - [ ] H5P_GET_FILE_LOCKING
      - [ ] H5P_GET_GC_REFERENCES
      - [ ] H5P_GET_LIBVER_BOUNDS
      - [ ] H5P_GET_MDC_CONFIG
      - [ ] H5P_GET_MDC_IMAGE_CONFIG
      - [ ] H5P_GET_MDC_LOG_OPTIONS
      - [ ] H5P_GET_META_BLOCK_SIZE
      - [ ] H5P_GET_METADATA_READ_ATTEMPTS
      - [ ] H5P_GET_MULTI_TYPE
      - [ ] H5P_GET_OBJECT_FLUSH_CB
      - [ ] H5P_GET_PAGE_BUFFER_SIZE
      - [ ] H5P_GET_SIEVE_BUF_SIZE
      - [ ] H5P_GET_SMALL_DATA_BLOCK_SIZE
      - [ ] H5P_GET_VOL_ID
      - [ ] H5P_GET_VOL_INFO
      - [ ] H5P_SET_ALIGNMENT
      - [ ] H5P_SET_CACHE
      - [ ] H5P_SET_COLL_METADATA_WRITE
      - [ ] H5P_SET_CORE_WRITE_TRACKING
      - [ ] H5P_SET_DRIVER
      - [ ] H5P_SET_ELINK_FILE_CACHE_SIZE
      - [ ] H5P_SET_EVICT_ON_CLOSE
      - [ ] H5P_SET_FAMILY_OFFSET
      - [ ] H5P_SET_FAPL_CORE
      - [ ] H5P_SET_FAPL_DIRECT
      - [ ] H5P_SET_FAPL_FAMILY
      - [ ] H5P_SET_FAPL_HDFS
      - [ ] H5P_SET_FAPL_LOG
      - [ ] H5P_SET_FAPL_MPIO
      - [ ] H5P_SET_FAPL_MULTI
      - [ ] H5P_SET_FAPL_ROS3
      - [ ] H5P_SET_FAPL_SEC2
      - [ ] H5P_SET_FAPL_SPLIT
      - [ ] H5P_SET_FAPL_SPLITTER
      - [ ] H5P_SET_FAPL_STDIO
      - [ ] H5P_SET_FAPL_WINDOWS
      - [ ] H5P_SET_FCLOSE_DEGREE
      - [ ] H5P_SET_FILE_IMAGE
      - [ ] H5P_SET_FILE_IMAGE_CALLBACKS
      - [ ] H5P_SET_FILE_LOCKING
      - [ ] H5P_SET_GC_REFERENCES
      - [ ] H5P_SET_LIBVER_BOUNDS
      - [ ] H5P_SET_MDC_CONFIG
      - [ ] H5P_SET_MDC_IMAGE_CONFIG
      - [ ] H5P_SET_MDC_LOG_OPTIONS
      - [ ] H5P_SET_META_BLOCK_SIZE
      - [ ] H5P_SET_METADATA_READ_ATTEMPTS
      - [ ] H5P_SET_MULTI_TYPE
      - [ ] H5P_SET_OBJECT_FLUSH_CB
      - [ ] H5P_SET_PAGE_BUFFER_SIZE
      - [ ] H5P_SET_SIEVE_BUF_SIZE
      - [ ] H5P_SET_SMALL_DATA_BLOCK_SIZE
      - [ ] H5P_SET_VOL
    - [ ] Group Creation
      - [ ] H5P_GET_EST_LINK_INFO
      - [ ] H5P_GET_LINK_CREATION_ORDER
      - [ ] H5P_GET_LINK_PHASE_CHANGE
      - [ ] H5P_GET_LOCAL_HEAP_SIZE_HINT
      - [ ] H5P_SET_EST_LINK_INFO
      - [ ] H5P_SET_LINK_CREATION_ORDER
      - [ ] H5P_SET_LINK_PHASE_CHANGE
      - [ ] H5P_SET_LOCAL_HEAP_SIZE_HINT
    - [ ] Attribute and Link Creation
      - [ ] H5P_GET_CHAR_ENCODING
      - [ ] H5P_GET_CREATE_INTERMEDIATE_GROUP
      - [ ] H5P_SET_CHAR_ENCODING
      - [ ] H5P_SET_CREATE_INTERMEDIATE_GROUP
    - [ ] Link Access
      - [ ] H5P_GET_ELINK_ACC_FLAGS
      - [ ] H5P_GET_ELINK_CB
      - [ ] H5P_GET_ELINK_FAPL
      - [ ] H5P_GET_ELINK_PREFIX
      - [ ] H5P_GET_NLINKS
      - [ ] H5P_SET_ELINK_ACC_FLAGS
      - [ ] H5P_SET_ELINK_CB
      - [ ] H5P_SET_ELINK_FAPL
      - [ ] H5P_SET_ELINK_PREFIX
      - [ ] H5P_SET_NLINKS
    - [ ] Dataset Creation
      - [ ] H5P_ALL_FILTERS_AVAIL
      - [ ] H5P_FILL_VALUE_DEFINED
      - [ ] H5P_GET_ALLOC_TIME
      - [ ] H5P_GET_CHUNK
      - [ ] H5P_GET_CHUNK_OPTS
      - [ ] H5P_GET_DSET_NO_ATTRS_HINT 
      - [ ] H5P_GET_EXTERNAL
      - [ ] H5P_GET_EXTERNAL_COUNT
      - [ ] H5P_GET_FILL_TIME
      - [ ] H5P_GET_FILL_VALUE
      - [ ] H5P_GET_FILTER
      - [ ] H5P_GET_FILTER_BY_ID
      - [ ] H5P_GET_LAYOUT
      - [ ] H5P_GET_NFILTERS
      - [ ] H5P_GET_VIRTUAL_COUNT
      - [ ] H5P_GET_VIRTUAL_DSETNAME
      - [ ] H5P_GET_VIRTUAL_FILENAME
      - [ ] H5P_GET_VIRTUAL_SRCSPACE
      - [ ] H5P_GET_VIRTUAL_VSPACE
      - [ ] H5P_MODIFY_FILTER
      - [ ] H5P_REMOVE_FILTER
      - [ ] H5P_SET_ALLOC_TIME
      - [ ] H5P_SET_CHUNK
      - [ ] H5P_SET_CHUNK_OPTS
      - [ ] H5P_SET_DEFLATE
      - [ ] H5P_SET_DSET_NO_ATTRS_HINT
      - [ ] H5P_SET_EXTERNAL
      - [ ] H5P_SET_FILL_TIME
      - [ ] H5P_SET_FILL_VALUE
      - [ ] H5P_SET_FILTER
      - [ ] H5P_SET_FLETCHER32
      - [ ] H5P_SET_LAYOUT
      - [ ] H5P_SET_NBIT
      - [ ] H5P_SET_SCALEOFFSET
      - [ ] H5P_SET_SHUFFLE
      - [ ] H5P_SET_SZIP
      - [ ] H5P_SET_VIRTUAL
    - [ ] Dataset Access
      - [ ] H5P_GET_APPEND_FLUSH
      - [ ] H5P_GET_CHUNK_CACHE
      - [ ] H5P_GET_EFILE_PREFIX
      - [ ] H5P_GET_VIRTUAL_PREFIX
      - [ ] H5P_GET_VIRTUAL_PRINTF_GAP
      - [ ] H5P_GET_VIRTUAL_VIEW
      - [ ] H5P_SET_APPEND_FLUSH
      - [ ] H5P_SET_CHUNK_CACHE
      - [ ] H5P_SET_EFILE_PREFIX
      - [ ] H5P_SET_VIRTUAL_PREFIX
      - [ ] H5P_SET_VIRTUAL_PRINTF_GAP
      - [ ] H5P_SET_VIRTUAL_VIEW
    - [ ] Dataset Transfer
      - [ ] H5P_GET_BTREE_RATIOS
      - [ ] H5P_GET_BUFFER
      - [ ] H5P_GET_DATA_TRANSFORM
      - [ ] H5P_GET_DXPL_MPIO
      - [ ] H5P_GET_EDC_CHECK
      - [ ] H5P_GET_HYPER_VECTOR_SIZE
      - [ ] H5P_GET_MPIO_ACTUAL_CHUNK_OPT_MODE
      - [ ] H5P_GET_MPIO_ACTUAL_IO_MODE
      - [ ] H5P_GET_MPIO_NO_COLLECTIVE_CAUSE
      - [ ] H5P_GET_TYPE_CONV_CB
      - [ ] H5P_GET_VLEN_MEM_MANAGER
      - [ ] H5P_SET_BTREE_RATIOS
      - [ ] H5P_SET_BUFFER
      - [ ] H5P_SET_DATA_TRANSFORM
      - [ ] H5P_SET_DXPL_MPIO
      - [ ] H5P_SET_DXPL_MPIO_CHUNK_OPT
      - [ ] H5P_SET_DXPL_MPIO_CHUNK_OPT_NUM
      - [ ] H5P_SET_DXPL_MPIO_CHUNK_OPT_RATIO
      - [ ] H5P_SET_DXPL_MPIO_COLLECTIVE_OPT
      - [ ] H5P_SET_EDC_CHECK
      - [ ] H5P_SET_FILTER_CALLBACK
      - [ ] H5P_SET_HYPER_VECTOR_SIZE
      - [ ] H5P_SET_TYPE_CONV_CB
      - [ ] H5P_SET_VLEN_MEM_MANAGER
    - [ ] Object Creation
      - [ ] H5P_GET_ATTR_CREATION_ORDER
      - [ ] H5P_GET_ATTR_PHASE_CHANGE
      - [ ] H5P_GET_OBJ_TRACK_TIMES
      - [ ] H5P_SET_ATTR_CREATION_ORDER
      - [ ] H5P_SET_ATTR_PHASE_CHANGE
      - [ ] H5P_SET_OBJ_TRACK_TIMES
    - [ ] Object Copy
      - [ ] H5P_ADD_MERGE_COMMITTED_DTYPE_PATH
      - [ ] H5P_FREE_MERGE_COMMITTED_DTYPE_PATHS
      - [ ] H5P_GET_COPY_OBJECT
      - [ ] H5P_GET_MCDT_SEARCH_CB
      - [ ] H5P_SET_COPY_OBJECT
      - [ ] H5P_SET_MCDT_SEARCH_CB
    - [ ] General Access Properties
      - [ ] H5P_GET_ALL_COLL_METADATA_OPS
      - [ ] H5P_SET_ALL_COLL_METADATA_OPS
    - [ ] General Property List Operations
      - [ ] H5P_CLOSE_CLASS
      - [ ] H5P_COPY_PROP
      - [ ] H5P_CREATE_CLASS
      - [ ] H5P_EQUAL
      - [ ] H5P_EXIST
      - [ ] H5P_GET
      - [ ] H5P_GET_CLASS_NAME
      - [ ] H5P_GET_CLASS_PARENT
      - [ ] H5P_GET_NPROPS
      - [ ] H5P_GET_SIZE
      - [ ] H5P_INSERT
      - [ ] H5P_ISA_CLASS
      - [ ] H5P_ITERATE
      - [ ] H5P_REGISTER
      - [ ] H5P_REMOVE
      - [ ] H5P_SET
      - [ ] H5P_UNREGISTER
  - [ ] References
    - [ ] H5R_COPY    
    - [ ] H5R_CREATE    
    - [ ] H5R_CREATE_ATTR
    - [ ] H5R_CREATE_OBJECT  
    - [ ] H5R_CREATE_REGION  
    - [ ] H5R_DEREFERENCE2
    - [ ] H5R_DESTROY 
    - [ ] H5R_EQUAL 
    - [ ] H5R_GET_ATTR_NAME 
    - [ ] H5R_GET_FILE_NAME
    - [ ] H5R_GET_NAME 
    - [ ] H5R_GET_OBJ_NAME 
    - [ ] H5R_GET_OBJ_TYPE2  
    - [ ] H5R_GET_OBJ_TYPE3     
    - [ ] H5R_GET_REGION   
    - [ ] H5R_GET_TYPE 
    - [ ] H5R_OPEN_ATTR  
    - [ ] H5R_OPEN_OBJECT
    - [ ] H5R_OPEN_REGION
  - [x] Virtual Object Layer
    - [x] H5VL_CLOSE
    - [x] H5VL_GET_CONNECTOR_ID
    - [x] H5VL_GET_CONNECTOR_ID_BY_NAME
    - [x] H5VL_GET_CONNECTOR_ID_BY_VALUE
    - [x] H5VL_GET_CONNECTOR_NAME
    - [x] H5VL_IS_CONNECTOR_REGISTERED_BY_NAME
    - [x] H5VL_IS_CONNECTOR_REGISTERED_BY_VALUE
    - [x] H5VL_REGISTER_CONNECTOR
    - [x] H5VL_REGISTER_CONNECTOR_BY_NAME
    - [x] H5VL_REGISTER_CONNECTOR_BY_VALUE
    - [x] H5VL_UNREGISTER_CONNECTOR
- [ ] High Level
  - [ ] Lite
    - [ ] H5LT_PATH_VALID
    - [ ] H5LT_OPEN_FILE_IMAGE
    - [ ] H5LT_MAKE_DATASET
    - [ ] H5LT_MAKE_DATASET_CHAR
    - [ ] H5LT_MAKE_DATASET_SHORT
    - [ ] H5LT_MAKE_DATASET_INT
    - [ ] H5LT_MAKE_DATASET_LONG
    - [ ] H5LT_MAKE_DATASET_FLOAT
    - [ ] H5LT_MAKE_DATASET_DOUBLE
    - [ ] H5LT_MAKE_DATASET_STRING
    - [ ] H5LT_READ_DATASET
    - [ ] H5LT_READ_DATASET_CHAR
    - [ ] H5LT_READ_DATASET_SHORT
    - [ ] H5LT_READ_DATASET_INT
    - [ ] H5LT_READ_DATASET_LONG
    - [ ] H5LT_READ_DATASET_FLOAT
    - [ ] H5LT_READ_DATASET_DOUBLE
    - [ ] H5LT_READ_DATASET_STRING
    - [ ] H5LT_FIND_DATASET
    - [ ] H5LT_GET_DATASET_NDIMS
    - [ ] H5LT_GET_DATASET_INFO
    - [ ] H5LD_GET_DSET_DIMS
    - [ ] H5LD_GET_DSET_ELMTS
    - [ ] H5LD_GET_DSET_TYPE_SIZE
    - [ ] H5LT_TEXT_TO_DTYPE
    - [ ] H5LT_DTYPE_TO_TEXT
    - [ ] H5LT_SET_ATTRIBUTE_STRING
    - [ ] H5LT_SET_ATTRIBUTE_CHAR
    - [ ] H5LT_SET_ATTRIBUTE_UCHAR
    - [ ] H5LT_SET_ATTRIBUTE_SHORT
    - [ ] H5LT_SET_ATTRIBUTE_USHORT
    - [ ] H5LT_SET_ATTRIBUTE_INT
    - [ ] H5LT_SET_ATTRIBUTE_UINT
    - [ ] H5LT_SET_ATTRIBUTE_LONG
    - [ ] H5LT_SET_ATTRIBUTE_LONG_LONG
    - [ ] H5LT_SET_ATTRIBUTE_ULONG
    - [ ] H5LT_SET_ATTRIBUTE_FLOAT
    - [ ] H5LT_SET_ATTRIBUTE_DOUBLE
    - [ ] H5LT_GET_ATTRIBUTE
    - [ ] H5LT_GET_ATTRIBUTE_STRING
    - [ ] H5LT_GET_ATTRIBUTE_CHAR
    - [ ] H5LT_GET_ATTRIBUTE_UCHAR
    - [ ] H5LT_GET_ATTRIBUTE_SHORT
    - [ ] H5LT_GET_ATTRIBUTE_USHORT
    - [ ] H5LT_GET_ATTRIBUTE_INT
    - [ ] H5LT_GET_ATTRIBUTE_UINT
    - [ ] H5LT_GET_ATTRIBUTE_LONG
    - [ ] H5LT_GET_ATTRIBUTE_LONG_LONG
    - [ ] H5LT_GET_ATTRIBUTE_ULONG
    - [ ] H5LT_GET_ATTRIBUTE_FLOAT
    - [ ] H5LT_GET_ATTRIBUTE_DOUBLE
    - [ ] H5LT_FIND_ATTRIBUTE
    - [ ] H5LT_GET_ATTRIBUTE_INFO
    - [ ] H5LT_GET_ATTRIBUTE_NDIMS
  - [ ] Images
    - [ ] H5IM_GET_IMAGE_INFO
    - [ ] H5IM_GET_NPALETTES
    - [ ] H5IM_GET_PALETTE
    - [ ] H5IM_GET_PALETTE_INFO
    - [ ] H5IM_IS_IMAGE
    - [ ] H5IM_IS_PALETTE
    - [ ] H5IM_LINK_PALETTE
    - [ ] H5IM_MAKE_IMAGE_8BIT
    - [ ] H5IM_MAKE_IMAGE_24BIT
    - [ ] H5IM_MAKE_PALETTE
    - [ ] H5IM_READ_IMAGE
    - [ ] H5IM_UNLINK_PALETTE
  - [ ] Tables
    - [ ] H5TB_MAKE_TABLE
    - [ ] H5TB_APPEND_RECORDS
    - [ ] H5TB_WRITE_RECORDS
    - [ ] H5TB_WRITE_FIELDS_NAME
    - [ ] H5TB_WRITE_FIELDS_INDEX
    - [ ] H5TB_DELETE_RECORD
    - [ ] H5TB_INSERT_RECORD
    - [ ] H5TB_ADD_RECORDS_FROM
    - [ ] H5TB_COMBINE_TABLES
    - [ ] H5TB_INSERT_FIELD
    - [ ] H5TB_DELETE_FIELD
    - [ ] H5TB_READ_TABLE
    - [ ] H5TB_READ_RECORDS
    - [ ] H5TB_READ_FIELDS_NAME
    - [ ] H5TB_READ_FIELDS_INDEX
    - [ ] H5TB_GET_TABLE_INFO
    - [ ] H5TB_GET_FIELD_INFO
    - [ ] H5TBA_GET_FILL
    - [ ] H5TBA_GET_TITLE
  - [ ] Packet Tables
    - [ ] H5PT_APPEND
    - [ ] H5PT_CLOSE
    - [ ] H5PT_CREATE
    - [ ] H5PT_CREATE_FL
    - [ ] H5PT_CREATE_INDEX
    - [ ] H5PT_FREE_VLEN_BUFF
    - [ ] H5PT_GET_DATASET
    - [ ] H5PT_GET_INDEX
    - [ ] H5PT_GET_NEXT
    - [ ] H5PT_GET_NUM_PACKETS
    - [ ] H5PT_GET_TYPE
    - [ ] H5PT_IS_VALID
    - [ ] H5PT_IS_VARLEN
    - [ ] H5PT_OPEN
    - [ ] H5PT_READ_PACKETS
    - [ ] H5PT_SET_INDEX
  - [ ] Dimension Scales
    - [ ] H5DS_ATTACH_SCALE
    - [ ] H5DS_DETACH_SCALE
    - [ ] H5DS_GET_LABEL
    - [ ] H5DS_GET_NUM_SCALES
    - [ ] H5DS_GET_SCALE_NAME
    - [ ] H5DS_IS_ATTACHED
    - [ ] H5DS_IS_SCALE
    - [ ] H5DS_ITERATE_SCALES
    - [ ] H5DS_SET_LABEL
    - [ ] H5DS_SET_SCALE
  - [ ] Optimizations
    - [ ] H5DO_APPEND
  - [ ] Extensions
    - [ ] H5LR_COPY_REFERENCE
    - [ ] H5LR_COPY_REGION
    - [ ] H5LR_CREATE_REF_TO_ALL
    - [ ] H5LR_CREATE_REGION_REFERENCES
    - [ ] H5LR_GET_REGION_INFO
    - [ ] H5LR_MAKE_DATASET
    - [ ] H5LR_READ_REGION
    - [ ] H5LT_COPY_REGION
    - [ ] H5LT_READ_BITFIELD_VALUE
    - [ ] H5LT_READ_REGION
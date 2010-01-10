using System;
using System.Runtime.InteropServices;
using Steam4NET;

namespace Steam4NET
{
	public enum EServerMode
	{
		eServerModeInvalid = 0,
		eServerModeNoAuthentication = 1,
		eServerModeAuthentication = 2,
		eServerModeAuthenticationAndSecure = 3,
	}
	
	public enum k_EFriendFlags
	{
		k_EFriendFlagNone = 0,
		k_EFriendFlagBlocked = 1,
		k_EFriendFlagFriendshipRequested = 2,
		k_EFriendFlagImmediate = 4,
		k_EFriendFlagClanMember = 8,
		k_EFriendFlagOnGameServer = 16,
		k_EFriendFlagRequestingFriendship = 128,
		k_EFriendFlagRequestingInfo = 256,
		k_EFriendFlagIgnored = 512,
		k_EFriendFlagIgnoredFriend = 1024,
		k_EFriendFlagAll = 65535,
	}
	
	public enum ESNetSocketState
	{
		k_ESNetSocketStateInvalid = 0,
		k_ESNetSocketStateConnected = 1,
		k_ESNetSocketStateInitiated = 10,
		k_ESNetSocketStateLocalCandidatesFound = 11,
		k_ESNetSocketStateReceivedRemoteCandidates = 12,
		k_ESNetSocketStateChallengeHandshake = 15,
		k_ESNetSocketStateDisconnecting = 21,
		k_ESNetSocketStateLocalDisconnect = 22,
		k_ESNetSocketStateTimeoutDuringConnect = 23,
		k_ESNetSocketStateRemoteEndDisconnected = 24,
		k_ESNetSocketStateConnectionBroken = 25,
	}
	
	public enum ERegistrySubTree
	{
		k_ERegistrySubTreeNews = 0,
		k_ERegistrySubTreeApps = 1,
		k_ERegistrySubTreeSubscriptions = 2,
		k_ERegistrySubTreeGameServers = 3,
		k_ERegistrySubTreeFriends = 4,
		k_ERegistrySubTreeSystem = 5,
	}
	
	public enum ESteamBufferMethod
	{
		eSteamBufferMethodFBF = 0,
		eSteamBufferMethodNBF = 1,
	}
	
	public enum EPurchaseResultDetail
	{
		k_EPurchaseResultNoDetail = 0,
		k_EPurchaseResultAVSFailure = 1,
		k_EPurchaseResultInsufficientFunds = 2,
		k_EPurchaseResultContactSupport = 3,
		k_EPurchaseResultTimeout = 4,
		k_EPurchaseResultInvalidPackage = 5,
		k_EPurchaseResultInvalidPaymentMethod = 6,
		k_EPurchaseResultInvalidData = 7,
		k_EPurchaseResultOthersInProgress = 8,
		k_EPurchaseResultAlreadyPurchased = 9,
		k_EPurchaseResultWrongPrice = 10,
	}
	
	public enum EDenyReason
	{
		k_EDenyInvalidVersion = 1,
		k_EDenyGeneric = 2,
		k_EDenyNotLoggedOn = 3,
		k_EDenyNoLicense = 4,
		k_EDenyCheater = 5,
		k_EDenyLoggedInElseWhere = 6,
		k_EDenyUnknownText = 7,
		k_EDenyIncompatibleAnticheat = 8,
		k_EDenyMemoryCorruption = 9,
		k_EDenyIncompatibleSoftware = 10,
		k_EDenySteamConnectionLost = 11,
		k_EDenySteamConnectionError = 12,
		k_EDenySteamResponseTimedOut = 13,
		k_EDenySteamValidationStalled = 14,
		k_EDenySteamOwnerLeftGuestUser = 15,
	}
	
	public enum EUniverse
	{
		k_EUniverseInvalid = 0,
		k_EUniversePublic = 1,
		k_EUniverseBeta = 2,
		k_EUniverseInternal = 3,
		k_EUniverseDev = 4,
		k_EUniverseRC = 5,
		k_EUniverseMax = 6,
	}
	
	public enum ELeaderboardSortMethod
	{
		k_ELeaderboardSortMethodNone = 0,
		k_ELeaderboardSortMethodAscending = 1,
		k_ELeaderboardSortMethodDescending = 2,
	}
	
	public enum ESystemIMType
	{
		k_ESystemIMRawText = 0,
		k_ESystemIMInvalidCard = 1,
		k_ESystemIMRecurringPurchaseFailed = 2,
		k_ESystemIMCardWillExpire = 3,
		k_ESystemIMSubscriptionExpired = 4,
		k_ESystemIMTypeMax = 5,
	}
	
	public enum EBeginAuthSessionResult
	{
		k_EBeginAuthSessionResultOK = 0,
		k_EBeginAuthSessionResultInvalidTicket = 1,
		k_EBeginAuthSessionResultDuplicateRequest = 2,
		k_EBeginAuthSessionResultInvalidVersion = 3,
		k_EBeginAuthSessionResultGameMismatch = 4,
		k_EBeginAuthSessionResultExpiredTicket = 5,
	}
	
	public enum ESNetSocketConnectionType
	{
		k_ESNetSocketConnectionTypeNotConnected = 0,
		k_ESNetSocketConnectionTypeUDP = 1,
		k_ESNetSocketConnectionTypeUDPRelay = 2,
	}
	
	public enum ENotificationPosition
	{
		k_EPositionTopLeft = 0,
		k_EPositionTopRight = 1,
		k_EPositionBottomLeft = 2,
		k_EPositionBottomRight = 3,
	}
	
	public enum EAccountType
	{
		k_EAccountTypeInvalid = 0,
		k_EAccountTypeIndividual = 1,
		k_EAccountTypeMultiseat = 2,
		k_EAccountTypeGameServer = 3,
		k_EAccountTypeAnonGameServer = 4,
		k_EAccountTypePending = 5,
		k_EAccountTypeContentServer = 6,
		k_EAccountTypeClan = 7,
		k_EAccountTypeChat = 8,
		k_EAccountTypeP2PSuperSeeder = 9,
		k_EAccountTypeAnonUser = 10,
		k_EAccountTypeMax = 11,
	}
	
	public enum ESteamSubscriptionBillingInfoType
	{
		ePaymentCardInfo = 1,
		ePrepurchasedInfo = 2,
		eAccountBillingInfo = 3,
		eExternalBillingInfo = 4,
		ePaymentCardReceipt = 5,
		ePrepurchaseReceipt = 6,
		eEmptyReceipt = 7,
	}
	
	public enum EBillingType
	{
		eNoCost = 0,
		eBillOnceOnly = 1,
		eBillMonthly = 2,
		eProofOfPrepurchaseOnly = 3,
		eGuestPass = 4,
		eHardwarePromo = 5,
		eGift = 6,
		eAutoGrant = 7,
		eNumBillingTypes = 8,
	}
	
	public enum EChatSteamIDInstanceFlags
	{
		k_EChatAccountInstanceMask = 4095,
		k_EChatInstanceFlagClan = 524288,
		k_EChatInstanceFlagLobby = 262144,
	}
	
	public enum ESteamServerType
	{
		eSteamValveCDKeyValidationServer = 0,
		eSteamHalfLifeMasterServer = 1,
		eSteamFriendsServer = 2,
		eSteamCSERServer = 3,
		eSteamHalfLife2MasterServer = 4,
		eSteamRDKFMasterServer = 5,
		eMaxServerTypes = 6,
	}
	
	public enum EAppUsageEvent
	{
		k_EAppUsageEventGameLaunch = 1,
		k_EAppUsageEventGameLaunchTrial = 2,
		k_EAppUsageEventMedia = 3,
		k_EAppUsageEventPreloadStart = 4,
		k_EAppUsageEventPreloadFinish = 5,
		k_EAppUsageEventMarketingMessageView = 6,
		k_EAppUsageEventInGameAdViewed = 7,
		k_EAppUsageEventGameLaunchFreeWeekend = 8,
	}
	
	public enum ELeaderboardDisplayType
	{
		k_ELeaderboardDisplayTypeNone = 0,
		k_ELeaderboardDisplayTypeNumeric = 1,
		k_ELeaderboardDisplayTypeTimeSeconds = 2,
		k_ELeaderboardDisplayTypeTimeMilliSeconds = 3,
	}
	
	public enum ECurrencyCode
	{
		k_ECurrencyCodeInvalid = 0,
		k_ECurrencyCodeUSD = 1,
		k_ECurrencyCodeGBP = 2,
		k_ECurrencyCodeEUR = 3,
		k_ECurrencyCodeMax = 4,
	}
	
	public enum EGCMsgResponse
	{
		k_EGCMsgResponseOK = 0,
		k_EGCMsgResponseDenied = 1,
		k_EGCMsgResponseServerError = 2,
		k_EGCMsgResponseTimeout = 3,
		k_EGCMsgResponseInvalid = 4,
		k_EGCMsgResponseNoMatch = 5,
		k_EGCMsgResponseUnknownError = 6,
		k_EGCMsgResponseNotLoggedOn = 7,
	}
	
	public enum ESteamAPICallFailure
	{
		k_ESteamAPICallFailureNone = -1,
		k_ESteamAPICallFailureSteamGone = 0,
		k_ESteamAPICallFailureNetworkFailure = 1,
		k_ESteamAPICallFailureInvalidHandle = 2,
		k_ESteamAPICallFailureMismatchedCallback = 3,
	}
	
	public enum EPurchaseStatus
	{
		k_EPurchasePending = 0,
		k_EPurchaseSucceeded = 1,
		k_EPurchaseFailed = 2,
		k_EPurchaseRefunded = 3,
		k_EPurchaseInit = 4,
		k_EPurchaseChargedback = 5,
		k_EPurchaseRevoked = 6,
	}
	
	public enum ESteamUserStatType
	{
		k_ESteamUserStatTypeINVALID = 0,
		k_ESteamUserStatTypeINT = 1,
		k_ESteamUserStatTypeFLOAT = 2,
		k_ESteamUserStatTypeAVGRATE = 3,
		k_ESteamUserStatTypeACHIEVEMENTS = 4,
		k_ESteamUserStatTypeGROUPACHIEVEMENTS = 5,
	}
	
	public enum EDepotBuildStatus
	{
		k_EDepotBuildStatusInvalid = -1,
		k_EDepotBuildStatusFailed = 0,
		k_EDepotBuildStatusProcessingConfig = 1,
		k_EDepotBuildStatusProcessingData = 2,
		k_EDepotBuildStatusUploadingData = 3,
		k_EDepotBuildStatusCompleted = 4,
	}
	
	public enum ELicenseFlags
	{
		k_ELicenseFlagRenew = 1,
		k_ELicenseFlagRenewalFailed = 2,
		k_ELicenseFlagPending = 4,
		k_ELicenseFlagExpired = 8,
		k_ELicenseFlagCancelledByUser = 16,
		k_ELicenseFlagCancelledByAdmin = 32,
	}
	
	public enum EAppState
	{
		k_EAppStateDownloading = 0,
		k_EAppStatePaused = 1,
		k_EAppStateDownloadComplete = 2,
	}
	
	public enum ELobbyType
	{
		k_ELobbyTypeFriendsOnly = 1,
		k_ELobbyTypePublic = 2,
	}
	
	public enum EChatRoomType
	{
		k_EChatRoomTypeFriend = 1,
		k_EChatRoomTypeMUC = 2,
		k_EChatRoomTypeLobby = 3,
	}
	
	public enum EFriendMsgType
	{
		k_EFriendMsgTypeChat = 1,
		k_EFriendMsgTypeTyping = 2,
		k_EFriendMsgTypeInvite = 3,
		k_EFriendMsgTypeChatSent = 4,
	}
	
	public enum ESteamPaymentCardType
	{
		eVisa = 1,
		eMaster = 2,
		eAmericanExpress = 3,
		eDiscover = 4,
		eDinnersClub = 5,
		eJCB = 6,
	}
	
	public enum EIFaceResult
	{
		IFACE_OK = 0,
		IFACE_FAILED = 1,
	}
	
	public enum EFriendRelationship
	{
		k_EFriendRelationshipNone = 0,
		k_EFriendRelationshipBlocked = 1,
		k_EFriendRelationshipRequestRecipient = 2,
		k_EFriendRelationshipFriend = 3,
		k_EFriendRelationshipRequestInitiator = 4,
		k_EFriendRelationshipIgnored = 5,
		k_EFriendRelationshipIgnoredFriend = 6,
	}
	
	public enum EMatchMakingServerResponse
	{
		eServerResponded = 0,
		eServerFailedToRespond = 1,
		eNoServersListedOnMasterServer = 2,
	}
	
	public enum ELobbyComparison
	{
		k_ELobbyComparisonEqualToOrLessThan = -2,
		k_ELobbyComparisonLessThan = -1,
		k_ELobbyComparisonEqual = 0,
		k_ELobbyComparisonGreaterThan = 1,
		k_ELobbyComparisonEqualToOrGreaterThan = 2,
	}
	
	public enum ENewsUpdateType
	{
		k_EAppNews = 0,
		k_ESteamAds = 1,
		k_ESteamNews = 2,
		k_ECDDBUpdate = 3,
		k_EClientUpdate = 4,
	}
	
	public enum ELogonState
	{
		k_ELogonStateNotLoggedOn = 0,
		k_ELogonStateLoggingOn = 1,
		k_ELogonStateLoggingOff = 2,
		k_ELogonStateLoggedOn = 3,
	}
	
	public enum ESteamSubscriptionStatus
	{
		eSteamSubscriptionOK = 0,
		eSteamSubscriptionPending = 1,
		eSteamSubscriptionPreorder = 2,
		eSteamSubscriptionPrepurchaseTransferred = 3,
		eSteamSubscriptionPrepurchaseInvalid = 4,
		eSteamSubscriptionPrepurchaseRejected = 5,
		eSteamSubscriptionPrepurchaseRevoked = 6,
		eSteamSubscriptionPaymentCardDeclined = 7,
		eSteamSubscriptionCancelledByUser = 8,
		eSteamSubscriptionCancelledByVendor = 9,
		eSteamSubscriptionPaymentCardUseLimit = 10,
		eSteamSubscriptionPaymentCardAlert = 11,
		eSteamSubscriptionFailed = 12,
		eSteamSubscriptionPaymentCardAVSFailure = 13,
		eSteamSubscriptionPaymentCardInsufficientFunds = 14,
		eSteamSubscriptionRestrictedCountry = 15,
	}
	
	public enum EAvatarSize
	{
		k_EAvatarSize32x32 = 0,
		k_EAvatarSize64x64 = 1,
	}
	
	public enum ECallState
	{
		k_ECallStateUnknown = 0,
		k_ECallStateWaiting = 1,
		k_ECallStateDialing = 2,
		k_ECallStateRinging = 3,
		k_ECallStateInCall = 4,
	}
	
	public enum ESteamFindFilter
	{
		eSteamFindLocalOnly = 0,
		eSteamFindRemoteOnly = 1,
		eSteamFindAll = 2,
	}
	
	public enum ESteamSeekMethod
	{
		eSteamSeekMethodSet = 0,
		eSteamSeekMethodCur = 1,
		eSteamSeekMethodEnd = 2,
	}
	
	public enum EItemQuality
	{
		k_EItemQuality_Normal = 0,
		k_EItemQuality_Common = 1,
		k_EItemQuality_Rare = 2,
		k_EItemQuality_Unique = 3,
		k_EItemQuality_Count = 4,
		k_EItemQuality_Unk5 = 5,
		k_EItemQuality_Unk6 = 6,
		k_EItemQuality_Community = 7,
		k_EItemQuality_Valve = 8,
		k_EItemQuality_Max = 255,
	}
	
	public enum ESteamNotify
	{
		eSteamNotifyTicketsWillExpire = 0,
		eSteamNotifyAccountInfoChanged = 1,
		eSteamNotifyContentDescriptionChanged = 2,
		eSteamNotifyPleaseShutdown = 3,
		eSteamNotifyNewContentServer = 4,
		eSteamNotifySubscriptionStatusChanged = 5,
		eSteamNotifyContentServerConnectionLost = 6,
		eSteamNotifyCacheLoadingCompleted = 7,
		eSteamNotifyCacheNeedsDecryption = 8,
		eSteamNotifyCacheNeedsRepair = 9,
		eSteamNotifyAppDownloading = 10,
		eSteamNotifyAppDownloadingPaused = 11,
	}
	
	public enum EChatEntryType
	{
		k_EChatEntryTypeChatMsg = 1,
		k_EChatEntryTypeTyping = 2,
		k_EChatEntryTypeInviteGame = 3,
		k_EChatEntryTypeEmote = 4,
		k_EChatEntryTypeLobbyGameStart = 5,
	}
	
	public enum ECallbackType
	{
		k_iSteamUserCallbacks = 100,
		k_iSteamGameServerCallbacks = 200,
		k_iSteamFriendsCallbacks = 300,
		k_iSteamBillingCallbacks = 400,
		k_iSteamMatchmakingCallbacks = 500,
		k_iSteamContentServerCallbacks = 600,
		k_iSteamUtilsCallbacks = 700,
		k_iClientFriendsCallbacks = 800,
		k_iClientUserCallbacks = 900,
		k_iSteamAppsCallbacks = 1000,
		k_iSteamUserStatsCallbacks = 1100,
		k_iSteamNetworkingCallbacks = 1200,
		k_iClientRemoteStorageCallbacks = 1300,
		k_iSteamUserItemsCallbacks = 1400,
		k_iSteamGameServerItemsCallbacks = 1500,
		k_iClientUtilsCallbacks = 1600,
		k_iSteamGameCoordinatorCallbacks = 1700,
	}
	
	public enum EVACBan
	{
		k_EVACBanGoldsrc = 0,
		k_EVACBanSource = 1,
		k_EVACBanDayOfDefeatSource = 2,
	}
	
	public enum EClanRank
	{
		k_EClanRankNone = 0,
		k_EClanRankOwner = 1,
		k_EClanRankOfficer = 2,
		k_EClanRankMember = 3,
	}
	
	public enum EItemCriteriaOperator
	{
		k_EOperator_String_EQ = 0,
		k_EOperator_Not = 1,
		k_EOperator_String_Not_EQ = 1,
		k_EOperator_Float_EQ = 2,
		k_EOperator_Float_Not_EQ = 3,
		k_EOperator_Float_LT = 4,
		k_EOperator_Float_Not_LT = 5,
		k_EOperator_Float_LTE = 6,
		k_EOperator_Float_Not_LTE = 7,
		k_EOperator_Float_GT = 8,
		k_EOperator_Float_Not_GT = 9,
		k_EOperator_Float_GTE = 10,
		k_EOperator_Float_Not_GTE = 11,
		k_EOperator_Subkey_Contains = 12,
		k_EOperator_Subkey_Not_Contains = 13,
		k_EItemCriteriaOperator_Count = 14,
	}
	
	public enum EChatRoomVoiceStatus
	{
		eChatRoomVoiceStatusBad = 0,
		eChatRoomVoiceStatusUnknownRoom = 1,
		eChatRoomVoiceStatusUnknownUser = 2,
		eChatRoomVoiceStatusNotSpeaking = 3,
		eChatRoomVoiceStatusConnectedSpeaking = 4,
		eChatRoomVoiceStatusConnectedSpeakingData = 5,
		eChatRoomVoiceStatusNotConnectedSpeaking = 6,
		eChatRoomVoiceStatusConnecting = 7,
		eChatRoomVoiceStatusUnreachable = 8,
		eChatRoomVoiceStatusDisconnected = 9,
		eChatRoomVoiceStatusCount = 10,
	}
	
	public enum EGCMessages
	{
		k_ESOMsg_Create = 21,
		k_ESOMsg_Update = 22,
		k_ESOMsg_Destroy = 23,
		k_ESOMsg_CacheSubscribed = 24,
		k_ESOMsg_CacheUnsubscribed = 25,
		k_EGCMsgStartPlaying = 53,
		k_EGCMsgStopPlaying = 54,
		k_EGCMsgStartGameserver = 55,
		k_EGCMsgStopGameserver = 56,
		k_EMsgGCSetItemPosition = 1001,
		k_EMsgGCCraft = 1002,
		k_EMsgGCCraftResponse = 1003,
		k_EMsgGCDelete = 1004,
		k_EMsgGCDev_NewItemRequest = 2001,
		k_EMsgGCDev_NewItemRequestResponse = 2002,
	}
	
	public enum EPaymentMethod
	{
		k_EPaymentMethodNone = 0,
		k_EPaymentMethodCDKey = 1,
		k_EPaymentMethodCreditCard = 2,
		k_EPaymentMethodPayPal = 4,
		k_EPaymentMethodManual = 8,
	}
	
	public enum EPersonaState
	{
		k_EPersonaStateOffline = 0,
		k_EPersonaStateOnline = 1,
		k_EPersonaStateBusy = 2,
		k_EPersonaStateAway = 3,
		k_EPersonaStateSnooze = 4,
		k_EPersonaStateMax = 5,
	}
	
	public enum ESteamAppUpdateStatsQueryType
	{
		ePhysicalBytesReceivedThisSession = 1,
		eAppReadyToLaunchStatus = 2,
		eAppPreloadStatus = 3,
		eAppEntireDepot = 4,
		eCacheBytesPresent = 5,
	}
	
	public enum ELeaderboardDataRequest
	{
		k_ELeaderboardDataRequestGlobal = 0,
		k_ELeaderboardDataRequestGlobalAroundUser = 1,
		k_ELeaderboardDataRequestFriends = 2,
	}
	
	public enum EConnectionPriority
	{
		k_EConnectionPriorityLow = 0,
		k_EConnectionPriorityMedium = 1,
		k_EConnectionPriorityHigh = 2,
	}
	
	public enum EAuthSessionResponse
	{
		k_EAuthSessionResponseOK = 0,
		k_EAuthSessionResponseUserNotConnectedToSteam = 1,
		k_EAuthSessionResponseNoLicenseOrExpired = 2,
		k_EAuthSessionResponseVACBanned = 3,
		k_EAuthSessionResponseLoggedInElseWhere = 4,
		k_EAuthSessionResponseVACCheckTimedOut = 5,
		k_EAuthSessionResponseAuthTicketCanceled = 6,
		k_EAuthSessionResponseAuthTicketInvalidAlreadyUsed = 7,
		k_EAuthSessionResponseAuthTicketInvalid = 8,
	}
	
	public enum EItemRequestResult
	{
		k_EItemRequestResultOK = 0,
		k_EItemRequestResultDenied = 1,
		k_EItemRequestResultServerError = 2,
		k_EItemRequestResultTimeout = 3,
		k_EItemRequestResultInvalid = 4,
		k_EItemRequestResultNoMatch = 5,
		k_EItemRequestResultUnknownError = 6,
		k_EItemRequestResultNotLoggedOn = 7,
	}
	
	public enum EClanRelationship
	{
		eClanRelationshipNone = 0,
		eClanRelationshipBlocked = 1,
		eClanRelationshipInvited = 2,
		eClanRelationshipMember = 3,
		eClanRelationshipKicked = 4,
	}
	
	public enum EResult
	{
		k_EResultOK = 1,
		k_EResultFail = 2,
		k_EResultNoConnection = 3,
		k_EResultInvalidPassword = 5,
		k_EResultLoggedInElsewhere = 6,
		k_EResultInvalidProtocolVer = 7,
		k_EResultInvalidParam = 8,
		k_EResultFileNotFound = 9,
		k_EResultBusy = 10,
		k_EResultInvalidState = 11,
		k_EResultInvalidName = 12,
		k_EResultInvalidEmail = 13,
		k_EResultDuplicateName = 14,
		k_EResultAccessDenied = 15,
		k_EResultTimeout = 16,
		k_EResultBanned = 17,
		k_EResultAccountNotFound = 18,
		k_EResultInvalidSteamID = 19,
		k_EResultServiceUnavailable = 20,
		k_EResultNotLoggedOn = 21,
		k_EResultPending = 22,
		k_EResultEncryptionFailure = 23,
		k_EResultInsufficientPrivilege = 24,
		k_EResultLimitExceeded = 25,
		k_EResultRevoked = 26,
		k_EResultExpired = 27,
		k_EResultAlreadyRedeemed = 28,
		k_EResultDuplicateRequest = 29,
		k_EResultAlreadyOwned = 30,
		k_EResultIPNotFound = 31,
		k_EResultPersistFailed = 32,
		k_EResultLockingFailed = 33,
		k_EResultLogonSessionReplaced = 34,
		k_EResultConnectFailed = 35,
		k_EResultHandshakeFailed = 36,
		k_EResultIOFailure = 37,
		k_EResultRemoteDisconnect = 38,
		k_EResultShoppingCartNotFound = 39,
		k_EResultBlocked = 40,
		k_EResultIgnored = 41,
		k_EResultNoMatch = 42,
		k_EResultAccountDisabled = 43,
		k_EResultServiceReadOnly = 44,
	}
	
	public enum EPersonaChange
	{
		k_EPersonaChangeName = 1,
		k_EPersonaChangeStatus = 2,
		k_EPersonaChangeComeOnline = 4,
		k_EPersonaChangeGoneOffline = 8,
		k_EPersonaChangeGamePlayed = 16,
		k_EPersonaChangeGameServer = 32,
		k_EPersonaChangeAvatar = 64,
		k_EPersonaChangeJoinedSource = 128,
		k_EPersonaChangeLeftSource = 256,
		k_EPersonaChangeRelationshipChanged = 512,
		k_EPersonaChangeNameFirstSet = 1024,
	}
	
	public enum EDetailedPlatformErrorType
	{
		eNoDetailedErrorAvailable = 0,
		eStandardCerrno = 1,
		eWin32LastError = 2,
		eWinSockLastError = 3,
		eDetailedPlatformErrorCount = 4,
	}
	
	public enum EVoiceResult
	{
		k_EVoiceResultOK = 0,
		k_EVoiceResultNotInitialized = 1,
		k_EVoiceResultNotRecording = 2,
		k_EVoiceResultNoData = 3,
		k_EVoiceResultBufferTooSmall = 4,
		k_EVoiceResultDataCorrupted = 5,
	}
	
	public enum ESteamError
	{
		eSteamErrorNone = 0,
		eSteamErrorUnknown = 1,
		eSteamErrorLibraryNotInitialized = 2,
		eSteamErrorLibraryAlreadyInitialized = 3,
		eSteamErrorConfig = 4,
		eSteamErrorContentServerConnect = 5,
		eSteamErrorBadHandle = 6,
		eSteamErrorHandlesExhausted = 7,
		eSteamErrorBadArg = 8,
		eSteamErrorNotFound = 9,
		eSteamErrorRead = 10,
		eSteamErrorEOF = 11,
		eSteamErrorSeek = 12,
		eSteamErrorCannotWriteNonUserConfigFile = 13,
		eSteamErrorCacheOpen = 14,
		eSteamErrorCacheRead = 15,
		eSteamErrorCacheCorrupted = 16,
		eSteamErrorCacheWrite = 17,
		eSteamErrorCacheSession = 18,
		eSteamErrorCacheInternal = 19,
		eSteamErrorCacheBadApp = 20,
		eSteamErrorCacheVersion = 21,
		eSteamErrorCacheBadFingerPrint = 22,
		eSteamErrorNotFinishedProcessing = 23,
		eSteamErrorNothingToDo = 24,
		eSteamErrorCorruptEncryptedUserIDTicket = 25,
		eSteamErrorSocketLibraryNotInitialized = 26,
		eSteamErrorFailedToConnectToUserIDTicketValidationServer = 27,
		eSteamErrorBadProtocolVersion = 28,
		eSteamErrorReplayedUserIDTicketFromClient = 29,
		eSteamErrorReceiveResultBufferTooSmall = 30,
		eSteamErrorSendFailed = 31,
		eSteamErrorReceiveFailed = 32,
		eSteamErrorReplayedReplyFromUserIDTicketValidationServer = 33,
		eSteamErrorBadSignatureFromUserIDTicketValidationServer = 34,
		eSteamErrorValidationStalledSoAborted = 35,
		eSteamErrorInvalidUserIDTicket = 36,
		eSteamErrorClientLoginRateTooHigh = 37,
		eSteamErrorClientWasNeverValidated = 38,
		eSteamErrorInternalSendBufferTooSmall = 39,
		eSteamErrorInternalReceiveBufferTooSmall = 40,
		eSteamErrorUserTicketExpired = 41,
		eSteamErrorCDKeyAlreadyInUseOnAnotherClient = 42,
		eSteamErrorNotLoggedIn = 101,
		eSteamErrorAlreadyExists = 102,
		eSteamErrorAlreadySubscribed = 103,
		eSteamErrorNotSubscribed = 104,
		eSteamErrorAccessDenied = 105,
		eSteamErrorFailedToCreateCacheFile = 106,
		eSteamErrorCallStalledSoAborted = 107,
		eSteamErrorEngineNotRunning = 108,
		eSteamErrorEngineConnectionLost = 109,
		eSteamErrorLoginFailed = 110,
		eSteamErrorAccountPending = 111,
		eSteamErrorCacheWasMissingRetry = 112,
		eSteamErrorLocalTimeIncorrect = 113,
		eSteamErrorCacheNeedsDecryption = 114,
		eSteamErrorAccountDisabled = 115,
		eSteamErrorCacheNeedsRepair = 116,
		eSteamErrorRebootRequired = 117,
		eSteamErrorNetwork = 200,
		eSteamErrorOffline = 201,
	}
	
	public enum EMatchMakingType
	{
		eInternetServer = 0,
		eLANServer = 1,
		eFriendsServer = 2,
		eFavoritesServer = 3,
		eHistoryServer = 4,
		eSpectatorServer = 5,
		eInvalidServer = 6,
	}
	
	public enum EChatRoomEnterResponse
	{
		k_EChatRoomEnterResponseSuccess = 1,
		k_EChatRoomEnterResponseDoesntExist = 2,
		k_EChatRoomEnterResponseNotAllowed = 3,
		k_EChatRoomEnterResponseFull = 4,
		k_EChatRoomEnterResponseError = 5,
		k_EChatRoomEnterResponseBanned = 6,
	}
	
	public unsafe struct GCSetItemPosition_t
	{
		UInt16 id;
		fixed SByte garbage[128];
		UInt64 itemID;
		UInt32 position;
		UInt32 unk1;
		const int k_iMessage = 1001;
	}
	
	public unsafe struct ClientAppNewsItemUpdate_t
	{
		Byte m_eNewsUpdateType;
		UInt32 m_uNewsID;
		UInt32 m_uAppID;
		const int k_iCallback = 110;
	}
	
	public unsafe struct SocketStatusCallback_t
	{
		UInt32 m_hSocket;
		UInt32 m_hListenSocket;
		CSteamID m_steamIDRemote;
		Int32 m_eSNetSocketState;
		const int k_iCallback = 1201;
	}
	
	public unsafe struct GSItemGranted_t
	{
		CSteamID m_steamID;
		UInt64 m_itemID;
		const int k_iCallback = 1507;
	}
	
	public unsafe struct SOMsgCacheUnsubscribed_t
	{
		UInt16 id;
		fixed SByte garbage[128];
		CSteamID steamid;
		const int k_iMessage = 25;
	}
	
	public unsafe struct GSPolicyResponse_t
	{
		Byte m_bSecure;
		const int k_iCallback = 115;
	}
	
	public unsafe struct PurchaseMsg_t
	{
		UInt32 m_bSuccess;
		EPurchaseResultDetail m_EPurchaseResultDetail;
		const int k_iCallback = 402;
	}
	
	public unsafe struct SOMsgCreate_t
	{
		UInt16 id;
		fixed SByte garbage[128];
		CSteamID steamid;
		UInt32 unknown;
		UInt64 itemid;
		UInt32 accountid;
		UInt16 itemtype;
		Byte itemlevel;
		Byte itemquality;
		UInt32 position;
		UInt32 itemcount;
		UInt16 attribcount;
		const int k_iMessage = 21;
	}
	
	public unsafe struct GSClientKick_t
	{
		CSteamID m_SteamID;
		EDenyReason m_eDenyReason;
		const int k_iCallback = 203;
	}
	
	public unsafe struct UserItemDeleted_t
	{
		UInt64 m_itemID;
		UInt32 Unk0;
		UInt32 Unk1;
		const int k_iCallback = 1402;
	}
	
	public unsafe struct PersonaStateChangeOld_t
	{
		UInt64 m_ulSteamID;
		Int32 m_ePersonaStatePrevious;
		Int32 m_nGameIDPrevious;
		UInt32 m_unGameServerIPPrevious;
		UInt16 m_usGameServerPortPrevious;
		const int k_iCallback = 303;
	}
	
	public unsafe struct GSClientDeny_t
	{
		CSteamID m_SteamID;
		EDenyReason m_eDenyReason;
		fixed SByte m_pchOptionalText[1024];
		const int k_iCallback = 202;
	}
	
	public unsafe struct GCCraftResponse_t
	{
		UInt16 id;
		fixed SByte garbage[128];
		UInt16 blueprint;
		UInt64 unk1;
		UInt64 itemid;
		const int k_iMessage = 1003;
	}
	
	public unsafe struct AppDataChanged_t
	{
		UInt32 m_Sequence;
		UInt32 m_Unknown;
		const int k_iCallback = 1001;
	}
	
	public unsafe struct LobbyDataUpdate_t
	{
		UInt64 m_ulSteamIDLobby;
		UInt64 m_ulSteamIDMember;
		const int k_iCallback = 505;
	}
	
	public unsafe struct GameServerChangeRequested_t
	{
		fixed SByte m_rgchServer[512];
		fixed SByte m_rgchPassword[512];
		const int k_iCallback = 332;
	}
	
	public unsafe struct FinalPriceMsg_t
	{
		UInt32 m_bSuccess;
		UInt32 m_nBaseCost;
		UInt32 m_nTotalDiscount;
		UInt32 m_nTax;
		UInt32 m_nShippingCost;
		const int k_iCallback = 401;
	}
	
	public unsafe struct LobbyGameCreated_t
	{
		UInt64 m_ulSteamIDLobby;
		UInt64 m_ulSteamIDGameServer;
		UInt32 m_unIP;
		UInt16 m_usPort;
		const int k_iCallback = 509;
	}
	
	public unsafe struct SteamShutdown_t
	{
		const int k_iCallback = 704;
	}
	
	public unsafe struct SOMsgCacheSubscribed_t
	{
		UInt16 id;
		fixed SByte garbage[128];
		CSteamID steamid;
		UInt32 unknown;
		UInt16 padding;
		UInt16 itemcount;
		const int k_iMessage = 24;
	}
	
	public unsafe struct ClientSteamNewsClientUpdate_t
	{
		Byte m_eNewsUpdateType;
		Byte m_bReloadCDDB;
		UInt32 m_unCurrentBootstrapperVersion;
		UInt32 m_unCurrentClientVersion;
		const int k_iCallback = 116;
	}
	
	public unsafe struct GSClientApprove_t
	{
		CSteamID m_SteamID;
		const int k_iCallback = 201;
	}
	
	public unsafe struct GSGameplayStats_t
	{
		EResult m_eResult;
		Int32 m_nRank;
		UInt32 m_unTotalConnects;
		UInt32 m_unTotalMinutesPlayed;
		const int k_iCallback = 207;
	}
	
	public unsafe struct LobbyChatUpdate_t
	{
		UInt64 m_ulSteamIDLobby;
		UInt64 m_ulSteamIDUserChanged;
		UInt64 m_ulSteamIDMakingChange;
		UInt32 m_rgfChatMemberStateChange;
		const int k_iCallback = 506;
	}
	
	public unsafe struct PrimaryChatDestinationSet_t
	{
		Byte m_bIsPrimary;
		const int k_iCallback = 114;
	}
	
	public unsafe struct UserAchievementStored_t
	{
		UInt64 m_nGameID;
		bool m_bGroupAchievement;
		fixed SByte m_rgchAchievementName[1024];
		UInt32 m_nCurProgress;
		UInt32 m_nMaxProgress;
		const int k_iCallback = 1103;
	}
	
	public unsafe struct GSClientAchievementStatus_t
	{
		UInt64 m_SteamID;
		fixed SByte m_pchAchievement[1024];
		bool m_bUnlocked;
		const int k_iCallback = 206;
	}
	
	public unsafe struct SOMsgDeleted_t
	{
		UInt16 id;
		fixed SByte garbage[128];
		CSteamID steamid;
		UInt32 unk1;
		UInt64 itemid;
		const int k_iMessage = 23;
	}
	
	public unsafe struct ValidateAuthTicketResponse_t
	{
		CSteamID m_SteamID;
		EAuthSessionResponse m_eAuthSessionResponse;
		const int k_iCallback = 143;
	}
	
	public unsafe struct BeginLogonRetry_t
	{
		const int k_iCallback = 104;
	}
	
	public unsafe struct GSClientSteam2Accept_t
	{
		UInt32 m_UserID;
		UInt64 m_SteamID;
		const int k_iCallback = 205;
	}
	
	public unsafe struct LobbyInvite_t
	{
		UInt64 m_ulSteamIDUser;
		UInt64 m_ulSteamIDLobby;
		const int k_iCallback = 503;
	}
	
	public unsafe struct GSItemRequest_t
	{
		CSteamID m_steamID;
		EItemRequestResult m_eResult;
		UInt64 m_itemID;
		const int k_iCallback = 1501;
	}
	
	public unsafe struct LobbyClosing_t
	{
		UInt64 m_ulSteamIDLobby;
		const int k_iCallback = 511;
	}
	
	public unsafe struct GCCraft_t
	{
		UInt16 id;
		fixed SByte garbage[128];
		UInt16 blueprint;
		UInt16 itemcount;
		const int k_iMessage = 1002;
	}
	
	public unsafe struct SteamServerConnectFailure_t
	{
		EResult m_eResult;
		const int k_iCallback = 102;
	}
	
	public unsafe struct FriendEndChatSession_t
	{
		CSteamID m_SteamID;
		const int k_iCallback = 312;
	}
	
	public unsafe struct LogonFailure_t
	{
		EResult m_eResult;
		const int k_iCallback = 102;
	}
	
	public unsafe struct LowBatteryPower_t
	{
		Byte m_nMinutesBatteryLeft;
		const int k_iCallback = 702;
	}
	
	public unsafe struct LobbyEnter_t
	{
		UInt64 m_ulSteamIDLobby;
		UInt32 m_rgfChatPermissions;
		bool m_bLocked;
		EChatRoomEnterResponse m_EChatRoomEnterResponse;
		const int k_iCallback = 504;
	}
	
	public unsafe struct GameLobbyJoinRequested_t
	{
		CSteamID m_steamIDLobby;
		CSteamID m_steamIDFriend;
		const int k_iCallback = 333;
	}
	
	public unsafe struct SteamServersDisconnected_t
	{
		EResult m_eResult;
		const int k_iCallback = 103;
	}
	
	public unsafe struct GSClientSteam2Deny_t
	{
		UInt32 m_UserID;
		UInt32 m_eSteamError;
		const int k_iCallback = 204;
	}
	
	public unsafe struct ClientSteamNewsItemUpdate_t
	{
		Byte m_eNewsUpdateType;
		UInt32 m_uNewsID;
		UInt32 m_uHaveSubID;
		UInt32 m_uNotHaveSubID;
		UInt32 m_uHaveAppID;
		UInt32 m_uNotHaveAppID;
		UInt32 m_uHaveAppIDInstalled;
		UInt32 m_uHavePlayedAppID;
		const int k_iCallback = 112;
	}
	
	public unsafe struct SteamAPICallCompleted_t
	{
		UInt64 m_hAsyncCall;
		const int k_iCallback = 703;
	}
	
	public unsafe struct CallbackPipeFailure_t
	{
		const int k_iCallback = 117;
	}
	
	public unsafe struct LeaderboardScoresDownloaded_t
	{
		UInt64 m_hSteamLeaderboard;
		UInt64 m_hSteamLeaderboardEntries;
		Int32 m_cEntryCount;
		const int k_iCallback = 1105;
	}
	
	public unsafe struct UserRequestingFriendship_t
	{
		UInt64 m_ulSteamID;
		const int k_iCallback = 302;
	}
	
	public unsafe struct FavoritesListChanged_t
	{
		UInt32 m_nIP;
		UInt32 m_nQueryPort;
		UInt32 m_nConnPort;
		UInt32 m_nAppID;
		UInt32 m_nFlags;
		bool m_bAdd;
		const int k_iCallback = 502;
	}
	
	public unsafe struct GSItemGetBlob_t
	{
		UInt64 m_itemID;
		EItemRequestResult m_eResult;
		fixed Byte m_itemBlob[8192];
		const int k_iCallback = 1508;
	}
	
	public unsafe struct GSItemCount_t
	{
		CSteamID m_steamID;
		EItemRequestResult m_eResult;
		UInt32 m_unCount;
		const int k_iCallback = 1500;
	}
	
	public unsafe struct GCDelete_t
	{
		UInt16 id;
		fixed SByte garbage[128];
		UInt64 itemID;
		const int k_iMessage = 1004;
	}
	
	public unsafe struct GSClientGroupStatus_t
	{
		CSteamID m_SteamIDUser;
		CSteamID m_SteamIDGroup;
		bool m_bMember;
		bool m_bOfficer;
		const int k_iCallback = 208;
	}
	
	public unsafe struct IPCFailure_t
	{
		Byte m_eFailureType;
		const int k_iCallback = 117;
		const int k_EFailureFlushedCallbackQueue = 0;
		const int k_EFailurePipeFail = 1;
	}
	
	public unsafe struct LobbyKicked_t
	{
		UInt64 m_ulSteamIDLobby;
		UInt64 m_ulSteamIDAdmin;
		const int k_iCallback = 512;
	}
	
	public unsafe struct SystemIM_t
	{
		UInt32 m_ESystemIMType;
		fixed SByte m_rgchMsgBody[32768];
		const int k_iCallback = 305;
	}
	
	public unsafe struct LobbyChatMsg_t
	{
		UInt64 m_ulSteamIDLobby;
		UInt64 m_ulSteamIDUser;
		EChatEntryType m_eChatEntryType;
		UInt32 m_iChatID;
		const int k_iCallback = 507;
	}
	
	public unsafe struct UserItemGranted_t
	{
		UInt64 m_itemID;
		CGameID m_gameID;
		const int k_iCallback = 1403;
	}
	
	public unsafe struct UserItemSetBlob_t
	{
		UInt64 m_itemID;
		EItemRequestResult m_eResult;
		UInt32 Unk;
		const int k_iCallback = 1405;
	}
	
	public unsafe struct LeaderboardFindResult_t
	{
		UInt64 m_hSteamLeaderboard;
		Byte m_bLeaderboardFound;
		const int k_iCallback = 1104;
	}
	
	public unsafe struct UserStatsStored_t
	{
		UInt64 m_nGameID;
		EResult m_eResult;
		const int k_iCallback = 1102;
	}
	
	public unsafe struct ClientGameServerDeny_t
	{
		UInt32 m_uAppID;
		UInt32 m_unGameServerIP;
		UInt16 m_usGameServerPort;
		UInt16 m_bSecure;
		UInt32 m_uReason;
		const int k_iCallback = 113;
	}
	
	public unsafe struct IPCountry_t
	{
		const int k_iCallback = 701;
	}
	
	public unsafe struct FriendChatMsg_t
	{
		UInt64 m_ulReceiver;
		UInt64 m_ulSender;
		UInt32 m_iUnknown1;
		UInt32 m_iChatID;
		const int k_iCallback = 306;
	}
	
	public unsafe struct LeaderboardScoreUploaded_t
	{
		Byte m_bSuccess;
		UInt64 m_hSteamLeaderboard;
		Int32 m_nScore;
		Byte m_bScoreChanged;
		Int32 m_nGlobalRankNew;
		Int32 m_nGlobalRankPrevious;
		const int k_iCallback = 1106;
	}
	
	public unsafe struct LobbyCreated_t
	{
		EResult m_eResult;
		UInt64 m_ulSteamIDLobby;
		const int k_iCallback = 513;
	}
	
	public unsafe struct LoggedOff_t
	{
		EResult m_eResult;
		const int k_iCallback = 103;
	}
	
	public unsafe struct SteamServersConnected_t
	{
		const int k_iCallback = 101;
	}
	
	public unsafe struct LobbyAdminChange_t
	{
		UInt64 m_ulSteamIDLobby;
		UInt64 m_ulSteamIDNewAdmin;
		const int k_iCallback = 508;
	}
	
	public unsafe struct Steam2TicketChanged_t
	{
		const int k_iCallback = 106;
	}
	
	public unsafe struct LobbyMatchList_t
	{
		UInt32 m_nLobbiesMatching;
		const int k_iCallback = 510;
	}
	
	public unsafe struct UserItemGetBlob_t
	{
		UInt64 m_itemID;
		EItemRequestResult m_eResult;
		fixed Byte itemBlob[8192];
		const int k_iCallback = 1404;
	}
	
	public unsafe struct GameOverlayActivated_t
	{
		Byte m_bActive;
		const int k_iCallback = 331;
	}
	
	public unsafe struct GameCoordinatorMessageAvailable_t
	{
		UInt32 messageLength;
		const int k_iCallback = 1701;
	}
	
	public unsafe struct UserItemMoved_t
	{
		UInt64 m_itemID;
		UInt32 Unk0;
		UInt32 Unk1;
		const int k_iCallback = 1401;
	}
	
	public unsafe struct PersonaStateChange_t
	{
		UInt64 m_ulSteamID;
		Int32 m_nChangeFlags;
		const int k_iCallback = 304;
	}
	
	public unsafe struct UserItemCount_t
	{
		CGameID m_gameID;
		EItemRequestResult m_eResult;
		UInt32 m_unCount;
		const int k_iCallback = 1400;
	}
	
	public unsafe struct SOMsgUpdate_t
	{
		UInt16 id;
		fixed SByte garbage[128];
		CSteamID steamid;
		UInt32 unk1;
		UInt64 itemID;
		UInt16 unk2;
		UInt32 position;
		const int k_iMessage = 22;
	}
	
	public unsafe struct LogonSuccess_t
	{
		const int k_iCallback = 101;
	}
	
	public unsafe struct UserStatsReceived_t
	{
		UInt64 m_nGameID;
		EResult m_eResult;
		CSteamID m_steamIDUser;
		const int k_iCallback = 1101;
	}
	
	public unsafe struct UserPolicyResponse_t
	{
		Byte m_bSecure;
		const int k_iCallback = 115;
	}
	
	public unsafe struct DlcInstalled_t
	{
		UInt32 m_nAppID;
		const int k_iCallback = 1005;
	}
	
	public unsafe struct GSItemSetBlob_t
	{
		UInt64 m_itemID;
		EItemRequestResult m_eResult;
		UInt32 Unk;
		const int k_iCallback = 1509;
	}
	
	public unsafe struct FriendAdded_t
	{
		Byte m_bSuccess;
		UInt64 m_ulSteamID;
		const int k_iCallback = 301;
	}
	
	public unsafe struct IClientRemoteStorage
	{
	}
	
	public unsafe struct TSteamAppStats
	{
		UInt32 uNumApps;
		UInt32 uMaxNameChars;
		UInt32 uMaxInstallDirNameChars;
		UInt32 uMaxVersionLabelChars;
		UInt32 uMaxLaunchOptions;
		UInt32 uMaxLaunchOptionDescChars;
		UInt32 uMaxLaunchOptionCmdLineChars;
		UInt32 uMaxNumIcons;
		UInt32 uMaxIconSize;
		UInt32 uMaxDependencies;
	}
	
	public unsafe struct TSteamProgress
	{
		Int32 bValid;
		UInt32 uPercentDone;
		fixed SByte szProgress[2040];
	}
	
	public unsafe struct TSteamPaymentCardInfo
	{
		ESteamPaymentCardType eCardType;
		fixed SByte szCardNumber[144];
		fixed SByte szCardHolderName[808];
		fixed SByte szCardExpYear[40];
		fixed SByte szCardExpMonth[24];
		fixed SByte szCardCVV2[48];
		fixed SByte szBillingAddress1[1032];
		fixed SByte szBillingAddress2[1032];
		fixed SByte szBillingCity[408];
		fixed SByte szBillingZip[136];
		fixed SByte szBillingState[264];
		fixed SByte szBillingCountry[264];
		fixed SByte szBillingPhone[168];
		fixed SByte szBillingEmailAddress[808];
		UInt32 uExpectedCostInCents;
		UInt32 uExpectedTaxInCents;
		fixed SByte szShippingName[808];
		fixed SByte szShippingAddress1[1032];
		fixed SByte szShippingAddress2[1032];
		fixed SByte szShippingCity[408];
		fixed SByte szShippingZip[136];
		fixed SByte szShippingState[264];
		fixed SByte szShippingCountry[264];
		fixed SByte szShippingPhone[168];
		UInt32 uExpectedShippingCostInCents;
	}
	
	public unsafe struct ISteamUser
	{
	}
	
	public unsafe struct ISteamMatchmakingServers
	{
	}
	
	public unsafe struct FriendGameInfo_t
	{
		CGameID m_gameID;
		UInt32 m_unGameIP;
		UInt16 m_usGamePort;
		UInt16 m_usQueryPort;
		CSteamID m_steamIDLobby;
	}
	
	public unsafe struct TSteamAppDependencyInfo
	{
		UInt32 AppId;
		UInt32 IsRequired;
		fixed SByte szMountName[2040];
	}
	
	public unsafe struct TSteamElemInfo
	{
		Int32 bIsDir;
		UInt32 uSizeOrCount;
		Int32 bIsLocal;
		fixed SByte cszName[2040];
		Int32 lLastAccessTime;
		Int32 lLastModificationTime;
		Int32 lCreationTime;
	}
	
	public unsafe struct IClientNetworking
	{
	}
	
	public unsafe struct TSteamExternalBillingInfo
	{
		fixed SByte szAccountName[808];
		fixed SByte szPassword[648];
	}
	
	public unsafe struct TSteamPrepurchaseInfo
	{
		fixed SByte szTypeOfProofOfPurchase[168];
		UInt32 uLengthOfBinaryProofOfPurchaseToken;
		fixed SByte cBinaryProofOfPurchaseToken[1608];
	}
	
	public unsafe struct TSteamSubscriptionBillingInfo
	{
		ESteamSubscriptionBillingInfoType eBillingInfoType;

		[System.Runtime.InteropServices.StructLayout(LayoutKind.Explicit)]
		struct Union
		{
			[System.Runtime.InteropServices.FieldOffset(0)]
			TSteamPaymentCardInfo PaymentCardInfo;
			[System.Runtime.InteropServices.FieldOffset(0)]
			TSteamPrepurchaseInfo PrepurchaseInfo;
			[System.Runtime.InteropServices.FieldOffset(0)]
			TSteamExternalBillingInfo ExternalBillingInfo;
			[System.Runtime.InteropServices.FieldOffset(0)]
			SByte bUseAccountBillingInfo;
		}
		
	}
	
	public unsafe struct TSTeamError
	{
		ESteamError eSteamError;
		EDetailedPlatformErrorType eDetailedErrorType;
		Int32 nDetailedErrorCode;
		fixed SByte szDesc[2040];
	}
	
	public unsafe struct CCallbackMgr
	{
	}
	
	public unsafe struct CallbackMsg_t
	{
		Int32 m_hSteamUser;
		Int32 m_iCallback;
		IntPtr m_pubParam;
		Int32 m_cubParam;
	}
	
	public unsafe struct TSteamApp
	{
		IntPtr szName;
		UInt32 uMaxNameChars;
		IntPtr szLatestVersionLabel;
		UInt32 uMaxLatestVersionLabelChars;
		IntPtr szCurrentVersionLabel;
		UInt32 uMaxCurrentVersionLabelChars;
		IntPtr szInstallDirName;
		UInt32 uMaxInstallDirNameChars;
		UInt32 uId;
		UInt32 uLatestVersionId;
		UInt32 uCurrentVersionId;
		UInt32 uMinCacheFileSizeMB;
		UInt32 uMaxCacheFileSizeMB;
		UInt32 uNumLaunchOptions;
		UInt32 uNumIcons;
		UInt32 uNumVersions;
		UInt32 uNumDependencies;
		IntPtr szUnkString;
	}
	
	public unsafe struct ConnectedUserInfo_t
	{
	}
	
	public unsafe struct ISteamApps
	{
	}
	
	public unsafe struct TSteamSubscriptionStats
	{
		UInt32 uNumSubscriptions;
		UInt32 uMaxNameChars;
		UInt32 uMaxApps;
	}
	
	public unsafe struct ISteamFriends
	{
	}
	
	public unsafe struct TSteamDiscountQualifier
	{
		fixed SByte szName[2040];
		UInt32 uRequiredSubscription;
		Int32 bIsDisqualifier;
	}
	
	public unsafe struct TSteamUpdateStats
	{
		UInt64 uBytesTotal;
		UInt64 uBytesPresent;
	}
	
	public unsafe struct TSteamPrepurchaseReceiptInfo
	{
		fixed SByte szTypeOfProofOfPurchase[168];
	}
	
	public unsafe struct ISteamContentServer
	{
	}
	
	public unsafe struct castable_string_t
	{
	}
	
	public unsafe struct TSteamPaymentCardReceiptInfo
	{
		ESteamPaymentCardType eCardType;
		fixed SByte szCardLastFourDigits[40];
		fixed SByte szCardHolderName[808];
		fixed SByte szBillingAddress1[1032];
		fixed SByte szBillingAddress2[1032];
		fixed SByte szBillingCity[408];
		fixed SByte szBillingZip[136];
		fixed SByte szBillingState[264];
		fixed SByte szBillingCountry[264];
		fixed SByte szCardApprovalCode[808];
		fixed SByte szTransDate[80];
		fixed SByte szTransTime[80];
		UInt32 uPriceWithoutTax;
		UInt32 uTaxAmount;
		UInt32 uShippingCost;
	}
	
	public unsafe struct IClientUserStats
	{
	}
	
	public unsafe struct ISteamGameServer
	{
	}
	
	public unsafe struct ISteamUserStats
	{
	}
	
	public unsafe struct ISteamMatchmaking
	{
	}
	
	public unsafe struct IClientGameServerItems
	{
	}
	
	public unsafe struct string_t
	{
		IntPtr pszValue;
	}
	
	public unsafe struct TSteamAppVersion
	{
		IntPtr szLabel;
		UInt32 uMaxLabelChars;
		UInt32 uVersionId;
		Int32 bIsNotAvailable;
	}
	
	public unsafe struct MatchMakingKeyValuePair_t
	{
		fixed SByte m_szKey[2048];
		fixed SByte m_szValue[2048];
	}
	
	public unsafe struct TSteamSplitLocalUserID
	{
		UInt32 Low32bits;
		UInt32 High32bits;
	}
	
	public unsafe struct TSteamGlobalUserID
	{
		UInt16 m_SteamInstanceID;

		[System.Runtime.InteropServices.StructLayout(LayoutKind.Explicit)]
		struct m_SteamLocalUserID
		{
			[System.Runtime.InteropServices.FieldOffset(0)]
			UInt64 As64bits;
			[System.Runtime.InteropServices.FieldOffset(0)]
			TSteamSplitLocalUserID Split;
		}
		
	}
	
	public unsafe struct SOMsgCacheSubscribed_Item_Attrib_t
	{
		UInt16 attribindex;
		float value;
	}
	
	public unsafe struct CSysModule
	{
	}
	
	public unsafe struct CallbackManager
	{
	}
	
	public unsafe struct ISteamGameServerItems
	{
	}
	
	public unsafe struct IConCommandBaseAccessor
	{
	}
	
	public unsafe struct ISteamRemoteStorage
	{
	}
	
	public unsafe struct ISteamUtils
	{
	}
	
	public unsafe struct ISteamClient
	{
	}
	
	public unsafe struct SOMsgCacheSubscribed_Item_t
	{
		UInt64 itemid;
		UInt32 accountid;
		UInt16 itemdefindex;
		Byte itemlevel;
		Byte itemquality;
		UInt32 position;
		UInt32 itemcount;
		UInt16 attribcount;
	}
	
	public unsafe struct IVAC
	{
	}
	
	public unsafe struct SteamSalt
	{
		fixed Byte uchSalt[64];
	}
	
	public unsafe struct ISteam2Bridge
	{
	}
	
	public unsafe struct IClientUserItems
	{
	}
	
	public unsafe struct TSteamAppLaunchOption
	{
		IntPtr szDesc;
		UInt32 uMaxDescChars;
		IntPtr szCmdLine;
		UInt32 uMaxCmdLineChars;
		UInt32 uIndex;
		UInt32 uIconIndex;
		Int32 bNoDesktopShortcut;
		Int32 bNoStartMenuShortcut;
		Int32 bIsLongRunningUnattended;
	}
	
	public unsafe struct LeaderboardEntry_t
	{
		CSteamID m_steamIDUser;
		Int32 m_nGlobalRank;
		Int32 m_nScore;
		Int32 m_cDetails;
	}
	
	public unsafe struct TSteamSubscription
	{
		IntPtr szName;
		UInt32 uMaxNameChars;
		IntPtr puAppIds;
		UInt32 uMaxAppIds;
		UInt32 uId;
		UInt32 uNumApps;
		EBillingType eBillingType;
		UInt32 uCostInCents;
		UInt32 uNumDiscounts;
		Int32 bIsPreorder;
		Int32 bRequiresShippingAddress;
		UInt32 uDomesticShippingCostInCents;
		UInt32 uInternationalShippingCostInCents;
		bool bIsCyberCafeSubscription;
		UInt32 uGameCode;
		fixed SByte szGameCodeDesc[2040];
		bool bIsDisabled;
		bool bRequiresCD;
		UInt32 uTerritoryCode;
		bool bIsSteam3Subscription;
	}
	
	public unsafe struct ISteamMasterServerUpdater
	{
	}
	
	public unsafe struct ISteamBilling
	{
	}
	
	public unsafe struct TSteamSubscriptionReceipt
	{
		ESteamSubscriptionStatus eStatus;
		ESteamSubscriptionStatus ePreviousStatus;
		ESteamSubscriptionBillingInfoType eReceiptInfoType;
		fixed SByte szConfirmationCode[136];

		[System.Runtime.InteropServices.StructLayout(LayoutKind.Explicit)]
		struct Union
		{
			[System.Runtime.InteropServices.FieldOffset(0)]
			TSteamPaymentCardReceiptInfo PaymentCardReceiptInfo;
			[System.Runtime.InteropServices.FieldOffset(0)]
			TSteamPrepurchaseReceiptInfo PrepurchaseReceiptInfo;
		}
		
	}
	
	public unsafe struct IClientMasterServerUpdater
	{
	}
	
	public unsafe struct IClientMatchmakingServers
	{
	}
	
	public unsafe struct TSteamSubscriptionDiscount
	{
		fixed SByte szName[2040];
		UInt32 uDiscountInCents;
		UInt32 uNumQualifiers;
	}
	
	public unsafe struct CNatTraversalStat
	{
	}
	
	public unsafe struct ISteamNetworking
	{
	}
	
	public unsafe struct TSteamOfflineStatus
	{
		Int32 eOfflineNow;
		Int32 eOfflineNextSession;
	}
	
}

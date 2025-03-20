#ifndef RUTIL_TEXT_VECTOR_READER_HPP
#define RUTIL_TEXT_VECTOR_READER_HPP
#include "Draw/Text_layout.hpp"
namespace RUtil{
enum class Text_ID{
    AbandonRunButton,AbstractCard,AbstractChest,AbstractCreature,AbstractDungeon,AbstractMonster,AbstractPlayer,AbstractPotion,AbstractRoom,AnyCardFromDeckToHandAction,ApplyPowerAction,ArmamentsAction,AscensionModeDescriptions,AscensionTextEffect,AttackFromDeckToHandAction,BattleStartEffect,BetterToHandAction,BossChest,BossRelicSelectScreen,CacheAction,CampfireSleepEffect,CampfireSmithEffect,CampfireTokeEffect,CampfireUI,Cancel_Button,CardLibSortHeader,CardLibraryScreen,CardRewardScreen,CharacterOption,CharacterSelectScreen,ChooseOneScreen,CombatRewardScreen,Confirm_Button,ConfirmPopup,CopyAction,CreditsScreen,DailyScreen,DeathScreen,DeathScreenUi,Dig_Option,DiscardAction,DiscardPilePanel,DiscardPileToHandAction,DiscardPileToTopOfDeckAction,DiscardPileViewScreen,DrawPilePanel,DrawPileViewScreen,DualWieldAction,DungeonMapScreen,DungeonTransitionScreen,EarlyAccessPopup,End_Turn_Button,ExhaustAction,ExhaustViewScreen,ExhumeAction,ExitGameButton,Exordium,GamblingChipAction,GameSavedEffect,GridCardSelectScreen,HandCardSelectScreen,HiddenChamberAction,ImmolateAction,InputSettingsScreen,LanguageDropdown,LeaderboardFilters,LeaderboardsScreen,Legend,Lift_Option,MainMenuScreen,MasterDeckViewScreen,MenuButton,MenuPanels,MerchantImageTextNotInGame,OpeningAction,OptionsPanel,PatchNotesScreen,PotionPopUp,PowerExpireTextEffect,Proceed_Button,PutOnDeckAction,RecycleAction,RelicViewScreen,RenamePanel,ReprieveAction,ReprogramAction,Rest_Option,RestartForChangesEffect,RetainCardsAction,RewardItem,RunHistoryPathNodes,RunHistoryScreen,SeedPanel,SettingsScreen,SetupAction,ShopRoom,SingleCardViewPopup,SingleViewRelicPopup,SkillFromDeckToHandAction,Smith_Option,StorePotion,TheBeyond,TheCity,TipHelper,Toke_Option,TopPanel,TreasureRoom,TreasureRoomBoss,TwitchVoter,Unlock_Confirm_Button,UnlockCharacterScreen,UnlockScreen,UnlockTextEffect,AscensionUnlockEffect,CustomModeScreen,ForethoughtAction,GainGoldTextEffect,SaveSlot,DeletePopup,SaveSlotScreen,RunHistoryMonsterNames,Period,Recall_Option,TheEnding,VictoryScreen,BetaArtUnlockEffect,RichPresence,MiscConsoleStrings,SignatureMoveMessage,PotionViewScreen,ClarityAction,WishAction,SyncMessage
};
class Text_Vector_Reader
{
public:
    Text_Vector_Reader()=delete;~Text_Vector_Reader()=delete;Text_Vector_Reader(const Text_Vector_Reader &) = delete;Text_Vector_Reader(Text_Vector_Reader &&) = delete;Text_Vector_Reader &operator=(const Text_Vector_Reader &) = delete;Text_Vector_Reader &operator=(Text_Vector_Reader &&) = delete;
    static std::shared_ptr<std::vector<Draw::Text_layout>> GetTextVector(const Text_ID id);
private:
    static void GetJsonFileText(const std::string &path);
    static void init_BOX();
    static std::vector<std::shared_ptr<std::vector<Draw::Text_layout>>> BOX;
};
}
#endif